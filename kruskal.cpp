#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int father[100];

void initialize_ufs();
int find_father(int child);
bool unionize(int child1, int child2);

struct edge
{
	int start;
	int end;
	int weight;
	bool operator<(const edge& b) const
	{
		return weight < b.weight;
	}
};
vector<edge> edge_table;
int edge_count, point_count;
int kruskal();

int main(void)
{
	cin >> point_count >> edge_count;
	for (int i = 0; i < edge_count; i++)
	{
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		edge cache;
		cache.end = c2;
		cache.start = c1;
		cache.weight = w;
		edge_table.push_back(cache);
	}
	int min_weight = kruskal();

	cout << min_weight << endl;
	system("pause");
	return 0;
}

void initialize_ufs()
{
	for (int i = 0; i < 100; i++)
	{
		father[i] = i;
	}
	return;
}

int find_father(int child)
{
	while (child != father[child])
		child = father[child];
	return child;
}

bool unionize(int child1, int child2)
{
	int f1 = find_father(child1);
	int f2 = find_father(child2);
	if (f1 == f2)
		return false;
	else
	{
		father[f2] = f1;
		return true;
	}
}

int kruskal()
{
	initialize_ufs();
	int ans = 0;
	int cur_edge_count = 0;
	sort(edge_table.begin(), edge_table.end());
	for (int i = 0; i < edge_table.size(); i++)
	{
		int father1 = find_father(edge_table[i].start);
		int father2 = find_father(edge_table[i].end);
		bool sentinal = unionize(father1, father2);
		if (sentinal == true)
		{
			cur_edge_count++;
			ans += edge_table[i].weight;
			if (cur_edge_count >= point_count - 1)
				break;
		}
	}
	if (cur_edge_count != point_count - 1)
		return -1;
	else
		return ans;
}