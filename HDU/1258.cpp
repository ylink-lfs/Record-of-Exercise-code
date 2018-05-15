#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b);
void partition_dfs(vector<int>& board, int start);
int get_sum(vector<int>& v);

int target;
int src_size;
bool check[15];
vector<string> res;
vector<int> board;
vector<int> src;

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> target >> src_size && src_size != 0)
	{
		
		memset(check, 0, sizeof(bool) * src_size);
		for (int i = 0; i < src_size; i++)
		{
			int cache;
			cin >> cache;
			src.push_back(cache);
		}
		sort(src.begin(), src.end(), cmp);
		cout << "Sums of " << target << ":\n";

		for (int i = 0; i < src.size(); i++)
		{
			board.clear();
			partition_dfs(board, i);
		}

		if (res.size() == 0)
		{
			cout << "NONE\n";
		}
		else
		{
			for (auto it = res.begin(); it != res.end(); it++)
				cout << *it << '\n';
		}

		res.clear();
		board.clear();
		src.clear();
	}
	return 0;
}

bool cmp(int a, int b)
{
	return a > b;
}

int get_sum(vector<int>& v)
{
	int res = 0;
	for (int i = 0; i < v.size(); i++)
		res += v[i];
	return res;
}

void partition_dfs(vector<int>& board, int start)
{
	int summy = get_sum(board);

	if (summy == target)
	{
		string cache;
		for (auto it = board.begin(); it < board.end(); it++)
		{
			cache += to_string(*it);
			if (it != board.end() - 1)
			{
				cache += '+';
			}
		}
		if (find(res.begin(), res.end(), cache) == res.end())
		{
			res.push_back(cache);
		}
		return;
	}
	if (summy > target)
		return;
	else
	{
		for (int i = start; i < src.size(); i++)
		{
			if (check[i] == false)  //num in i position didn't participate calculation
			{
				check[i] = true;
				board.push_back(src[i]);
				if (src[i] <= target && summy + src[i] <= target)
				{
					partition_dfs(board, i);
				}
				check[i] = false;
				board.erase(board.end() - 1);
			}
		}
	}
}
