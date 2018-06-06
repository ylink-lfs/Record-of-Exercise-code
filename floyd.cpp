#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int infinity = 0x3fffffff;
const int MAXV = 200;

int n, m;
int dis[MAXV][MAXV];

void floyd();

int main(void)
{
	int u, v, w;
	fill(dis[0], dis[0] + MAXV * MAXV, infinity);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		dis[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		dis[u][v] = w;
	}
	floyd();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dis[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

void floyd()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dis[i][k] != infinity && dis[k][j] != infinity)
				{
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
}