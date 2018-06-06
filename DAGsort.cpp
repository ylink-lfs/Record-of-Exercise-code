#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> adj_table[20];

struct sort_board
{
	int res_board[20];
	int cur = 0;
};

int point_count, edge_count;
int indegree[20];

bool topological_sort(int start_point);

int main(void)
{
	while (cin >> point_count >> edge_count)
	{
		fill(indegree, indegree + point_count, 0);
		for (int i = 0; i < point_count; i++)
		{
			adj_table[i].clear();
		}
		for (int i = 0; i < edge_count; i++)
		{
			int c1, c2, w;
			//omit w
			cin >> c1 >> c2 >> w;
			adj_table[c1].push_back(c2);
			indegree[c2]++;
		}
		bool check = topological_sort(0);
		if (check)
		{
			cout << "Graph is DAG\n";
		}
		else
		{
			cout << "Graph isn't DAG\n";
		}
	}
	return 0;
}

bool topological_sort(int start_point)
{
	queue<int> q;
	sort_board record;
	for (int i = 0; i < point_count; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int cur_index = q.front();
		q.pop();
		record.res_board[record.cur++] = cur_index;
		for (int i = 0; i < adj_table[cur_index].size(); i++)
		{
			int cur_dest = adj_table[cur_index][i];
			indegree[cur_dest]--;
			if (indegree[cur_dest] == 0)
			{
				q.push(cur_dest);
			}
		}
	}
	if (record.cur == point_count)
		return true;
	else
		return false;
}


/*
6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3

false
*/

/*
6 10
0 1 4
0 4 1
0 5 2
1 2 1
1 5 3
2 3 6
2 5 5
3 4 5
3 5 4
4 5 3

false
*/

/*
9 12
0 3 1
0 4 1
0 5 1
1 5 1
2 3 1
2 8 1
3 6 1
3 7 1
4 8 1
5 7 1
5 8 1
6 7 1

true
*/

/*
9 13
0 3 1
0 4 1
0 5 1
1 5 1
2 3 1
2 8 1
3 6 1
3 7 1
4 8 1
5 7 1
5 8 1
6 7 1
8 2 1

false
*/

/*
6 6
0 1 1
0 3 1
1 2 1
3 4 1
2 4 1
4 5 1

true
*/