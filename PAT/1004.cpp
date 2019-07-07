#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

vector<vector<int>> child_hierarchy;
vector<int> leave_count;

void init()
{
	leave_count.resize(1);
	child_hierarchy.clear();
}

void traverse_with_count(const vector<vector<int>>& tree)
{
	struct node
	{
		int id;
		int level;
		node(int id_, int level_) : id(id_), level(level_) {}
	};
	queue<node> q;
	int root_id = 1;
	q.push(node(root_id, 1));
	int prev_level = 0;
	while (!q.empty())
	{
		node cur(q.front());
		q.pop();
		if (prev_level != cur.level)
		{
			leave_count.push_back(0);
		}
		if (child_hierarchy[cur.id].empty())
		{
			leave_count[cur.level]++;
		}
		prev_level = cur.level;
		for (int i = 0; i < child_hierarchy[cur.id].size(); i++)
		{
			q.push(node(child_hierarchy[cur.id][i], cur.level + 1));
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	while (cin >> n >> m)
	{
		init();
		child_hierarchy.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			int id, k;
			cin >> id >> k;
			for (int j = 0; j < k; j++)
			{
				int t;
				cin >> t;
				child_hierarchy[id].push_back(t);
			}
		}
		traverse_with_count(child_hierarchy);
		for (int i = 1; i < leave_count.size(); i++)
		{
			cout << leave_count[i];
			if (i == leave_count.size() - 1)
			{
				cout << '\n';
			}
			else
			{
				cout << ' ';
			}
		}
	}
	return 0;
}