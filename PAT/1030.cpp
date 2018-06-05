#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

const int infinity = 0x3fffffff;

struct edge_info
{
	int dest;
	int dist;
	int cost;
};

vector<edge_info> adj_table[510];
vector<int> res;

int shortest_distance[510];
int current_price[510];
vector<int> pre[510];

int city_count, edge_count, start_city, end_city;

void dijkstra(int start_point);
void dfs(vector<int>& board, int end_city);
int get_price_sum(vector<int>& v);
int find_correspond_cost(int start, int end);

struct cmp
{
	bool operator()(int a, int b)
	{
		return shortest_distance[a] > shortest_distance[b];
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> city_count >> edge_count >> start_city >> end_city;
	for (int i = 0; i < edge_count; i++)
	{
		int c1, c2, d, c;
		cin >> c1 >> c2 >> d >> c;
		edge_info cache1, cache2;
		cache1.cost = cache2.cost = c;
		cache1.dist = cache2.dist = d;
		cache1.dest = c2;
		cache2.dest = c1;
		adj_table[c1].push_back(cache1);
		adj_table[c2].push_back(cache2);
	}

	dijkstra(start_city);
	vector<int> board;
	dfs(board, end_city);

	for (int i = res.size() - 1; i >= 0; i--)
	{
		cout << res[i] << ' ';
	}
	cout << shortest_distance[end_city] << ' ' << current_price[end_city] << '\n';

	return 0;
}

void dijkstra(int start_point)
{
	fill(shortest_distance, shortest_distance + city_count, infinity);
	fill(current_price, current_price + city_count, infinity);
	shortest_distance[start_point] = 0;
	current_price[start_point] = 0;
	priority_queue<int, vector<int>, cmp> q;
	for (int i = 0; i < city_count; i++)
	{
		q.push(i);
	}

	while (q.size())
	{
		int current_index = q.top();
		for (int i = 0; i < adj_table[current_index].size(); i++)
		{
			int cur_dest = adj_table[current_index][i].dest;
			int cur_cost = adj_table[current_index][i].cost;
			int cur_dist = adj_table[current_index][i].dist;
			if (shortest_distance[cur_dest] > shortest_distance[current_index] + cur_dist)
			{
				shortest_distance[cur_dest] = shortest_distance[current_index] + cur_dist;
				current_price[cur_dest] = current_price[current_index] + cur_cost;
				pre[cur_dest].clear();
				pre[cur_dest].push_back(current_index);
			}
			else if (shortest_distance[cur_dest] == shortest_distance[current_index] + cur_dist)
			{
				pre[cur_dest].push_back(current_index);
				if (current_price[cur_dest] > current_price[current_index] + cur_cost)
				{
					current_price[cur_dest] = current_price[current_index] + cur_cost;
				}
			}
		}
		q.pop();
	}
	return;
}

void dfs(vector<int>& board, int end_city)
{
	if (start_city == end_city)
	{
		board.push_back(end_city);
		int cur_sum = get_price_sum(res);
		int next_sum = get_price_sum(board);
		if (res.size() == 0 || cur_sum > next_sum)
		{
			res = board;
		}
		board.pop_back();
		return;
	}
	for (int i = 0; i < pre[end_city].size(); i++)
	{
		board.push_back(end_city);
		dfs(board, pre[end_city][i]);
		board.pop_back();
	}
}

int get_price_sum(vector<int>& v)
{	
	if (v.size() == 0 || v.size() == 1)
		return 0;
	else
	{
		int sum = 0;
		for (int i = v.size() - 1; i > 0; i--)
		{
			sum += find_correspond_cost(v[i], v[i - 1]);
		}
		return sum;
	}	
}

int find_correspond_cost(int start, int end)
{
	for (int i = 0; i < adj_table[start].size(); i++)
	{
		if (adj_table[start][i].dest == end)
		{
			return adj_table[start][i].cost;
		}
	}
	return -1;
}
