#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

struct edge_info
{
	int dest;
	int weight = 1;
};

vector<edge_info> adj_table[1005];
vector<edge_info> converse_adj_table[1005];
bool enedque[1005];
int level[1005];
int target_member_count;

int user_count, level_line;
vector<int> res_record;

void bfs_graph(int start_index);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> user_count >> level_line;
	for (int i = 0; i < user_count; i++)
	{
		int follow_count;
		cin >> follow_count;
		for (int j = 0; j < follow_count; j++)
		{
			int follower_id;
			cin >> follower_id;
			edge_info cache;
			edge_info cache2;
			cache.dest = follower_id - 1;
			cache2.dest = i;
			adj_table[i].push_back(cache);
			converse_adj_table[follower_id - 1].push_back(cache2);
		}
	}
	int query_count;
	cin >> query_count;
	for (int i = 0; i < query_count; i++)
	{
		int quer;
		cin >> quer;
		fill(enedque, enedque + user_count, 0);
		fill(level, level + user_count, 0);
		target_member_count = 0;
		bfs_graph(quer - 1);
		cout << target_member_count << '\n';
	}

	return 0;
}

void bfs_graph(int start_index)
{
	queue<int> q;
	q.push(start_index);
	enedque[start_index] = true;
	while (!q.empty())
	{
		int current_node = q.front();
		q.pop();
		if (level[current_node] > level_line)
		{
			break;
		}
		else if (level[current_node] > 0)
		{
			target_member_count++;
		}
		for (auto it = converse_adj_table[current_node].begin(); it < converse_adj_table[current_node].end(); it++)
		{
			if (enedque[(*it).dest] == false)
			{
				q.push((*it).dest);
				level[(*it).dest] = level[current_node] + 1;
				enedque[(*it).dest] = true;
			}
		}
	}
	return;
}
