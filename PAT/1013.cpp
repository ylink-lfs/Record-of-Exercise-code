#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> adj_table[1010];
bool visited[1010];
int city_count, edge_count;
int block_count;

void dfs(int start_index, int queryed_id);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int query_count;
	cin >> city_count >> edge_count >> query_count;
	for (int i = 0; i < edge_count; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		adj_table[c1 - 1].push_back(c2 - 1);
		adj_table[c2 - 1].push_back(c1 - 1);
	}
	for (int i = 0; i < query_count; i++)
	{
		int query_id;
		cin >> query_id;
		query_id--;
		block_count = 0;
		fill(visited, visited + city_count, 0);

		for (int i = 0; i < city_count; i++)
		{
			if (i == query_id)
				continue;
			if (visited[i] == false)
			{
				dfs(i, query_id);
				block_count++;
			}
		}
		cout << block_count - 1 << '\n';
	}

	return 0;
}

void dfs(int start_index, int queryed_id)
{
	visited[start_index] = true;
	for (int i = 0; i < adj_table[start_index].size(); i++)
	{
		if (adj_table[start_index][i] == queryed_id)
			continue;
		if (visited[adj_table[start_index][i]] == false)
		{
			dfs(adj_table[start_index][i], queryed_id);
		}
	}
	return;
}
