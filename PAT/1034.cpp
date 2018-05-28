#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

map<string, int> str_conversion;
map<string, int> gang_record;
map<int, string> str_reconv;

int matrix[2010][2010];
bool visited[2010];
int node_weight[2010];

int total_people;
int edge_count, weight_line;

int str_convert(const string& str);
void dfs(int& cur_member, int& cur_head, int& cur_weight, int cur_man);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> edge_count >> weight_line;
	for (int i = 0; i < edge_count; i++)
	{
		string cache1, cache2;
		int cur_weight;
		cin >> cache1 >> cache2 >> cur_weight;
		
		int id1 = str_convert(cache1);
		int id2 = str_convert(cache2);

		node_weight[id1] += cur_weight;
		node_weight[id2] += cur_weight;
		matrix[id1][id2] += cur_weight;
		matrix[id2][id1] += cur_weight;
	}
	for (int i = 0; i < total_people; i++)
	{
		int member_count = 0;
		int head_member = i;
		int weight_sum = 0;
		if (visited[i] == false)
		{
			dfs(member_count, head_member, weight_sum, i);
			weight_sum /= 2;
			if (member_count > 2 && weight_sum > weight_line)
			{
				string cache = str_reconv[head_member];
				gang_record[cache] = member_count;
			}
		}
	}
	cout << gang_record.size() << '\n';
	for (auto it = gang_record.begin(); it != gang_record.end(); it++)
	{
		cout << it->first << ' ' << it->second << '\n';
	}

	return 0;
}

int str_convert(const string& str)
{
	if (str_conversion.find(str) == str_conversion.end())
	{
		str_conversion[str] = total_people++;
		str_reconv[total_people - 1] = str;
		return total_people - 1;
	}
	else
	{
		return str_conversion[str];
	}
}

void dfs(int& cur_member, int& cur_head, int& cur_weight, int cur_man)
{
	visited[cur_man] = true;
	cur_weight += node_weight[cur_man];
	if (node_weight[cur_head] < node_weight[cur_man])
		cur_head = cur_man;
	cur_member++;
	for (int i = 0; i < total_people; i++)
	{
		if (matrix[cur_man][i] && visited[i] == false)
		{
			dfs(cur_member, cur_head, cur_weight, i);
		}
	}
	return;
}

/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/
