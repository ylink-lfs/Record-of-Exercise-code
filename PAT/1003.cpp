//Is there negative edge weight in this problem? I tried dijkstra algo, but failed online judge multiple times
//I passed the problem by Bellman-Ford algo
//Check gxx's solotion at night
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

const int infinity = 0x3fffffff;

struct edge_info
{
	int dest;
	int w;
};

vector<edge_info> adj_table[510];
int shortest_dist[510];
int diff_route[510];
int node_weight[510];
int weight_sum[510];

int start_p, end_p, city_num, edge_num;
set<int> pre[510];

bool bellman(int start_index);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> city_num >> edge_num >> start_p >> end_p;
	for (int i = 0; i < city_num; i++)
	{
		cin >> node_weight[i];
	}
	for (int i = 0; i < edge_num; i++)
	{
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		edge_info cache1, cache2;
		cache1.dest = c2;
		cache2.dest = c1;
		cache1.w = cache2.w = w;
		adj_table[c1].push_back(cache1);
		adj_table[c2].push_back(cache2);
	}
	bellman(start_p);
	cout << diff_route[end_p] << ' ' << weight_sum[end_p] << '\n';


	return 0;
}

bool bellman(int start_index)
{
	fill(shortest_dist, shortest_dist + city_num, infinity);
	fill(diff_route, diff_route + city_num, 0);
	fill(weight_sum, weight_sum + city_num, 0);

	shortest_dist[start_index] = 0;
	diff_route[start_index] = 1;
	weight_sum[start_index] = node_weight[start_index];

	int it_index = city_num - 1;
	while (it_index--)
	{
		bool optimize = false;
		for (int i = 0; i < city_num; i++)
		{
			for (int j = 0; j < adj_table[i].size(); j++)
			{
				//weight can be optimized or not
				int cur_dest = adj_table[i][j].dest;
				int cur_w = adj_table[i][j].w;
				if (shortest_dist[cur_dest] > shortest_dist[i] + cur_w)
				{
					//update shortest_dist[], diff_route[], weight_sum[]
					shortest_dist[cur_dest] = shortest_dist[i] + cur_w;
					weight_sum[cur_dest] = weight_sum[i] + node_weight[cur_dest];

					//think how to update diff_route[]
					diff_route[cur_dest] = diff_route[i];
					pre[cur_dest].clear();
					pre[cur_dest].insert(i);
					optimize = true;
				}
				else if (shortest_dist[cur_dest] == shortest_dist[i] + cur_w)
				{
					//always update diff_route[], check to update weight_sum[] or not
					//think how to update diff_route[]
					pre[cur_dest].insert(i);
					diff_route[cur_dest] = 0;
					for (auto it = pre[cur_dest].begin(); it != pre[cur_dest].end(); it++)
					{
						diff_route[cur_dest] += diff_route[*it];
					}
					if (weight_sum[cur_dest] < weight_sum[i] + node_weight[cur_dest])
					{
						weight_sum[cur_dest] = weight_sum[i] + node_weight[cur_dest];
					}
					optimize = true;
				}
			}
		}
		if (!optimize)
			return true;
	}

	//check negative weight circle
	for (int i = 0; i < city_num; i++)
	{
		for (int j = 0; j < adj_table[i].size(); j++)
		{
			
			int cur_dest = adj_table[i][j].dest;
			int cur_w = adj_table[i][j].w;
			if (shortest_dist[cur_dest] > shortest_dist[i] + cur_w)
			{
				return false;
			}			
		}
	}
	return true;
}
