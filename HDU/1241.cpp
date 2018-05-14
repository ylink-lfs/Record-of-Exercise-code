#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

struct point
{
	int x, y;
};

char board[100][100];
bool visited[100][100];  //be aware of the meaning of visited[][] in BFS

int m, n;

void dfs(int x, int y);

void bfs(point p);
bool check(point p);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> m >> n && m)
	{
		while (cin.get() != '\n')
			continue;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
			}
			while (cin.get() != '\n')
				continue;
		}
		memset(visited, false, sizeof(bool) * 100 * 100);
		int counter = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == '*')
					continue;
				if (visited[i][j] == true)
					continue;
				if (board[i][j] == '@' && visited[i][j] == false)
				{
					counter++;
					point store;
					store.x = i;
					store.y = j;
					bfs(store);
				}
			}
		}
		cout << counter << '\n';
	}

	return 0;
}

void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return;
	if (visited[x][y] == true)
		return;

	if (board[x][y] == '*')
		return;
	visited[x][y] = true;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
			dfs(x + i, y + j);
	}
}

void bfs(point p)
{
	queue<point> q;
	q.push(p);
	visited[p.x][p.y] = true;
	while (!q.empty())
	{
		point current = q.front();
		q.pop();
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				point cache;
				cache.x = current.x + i;
				cache.y = current.y + j;
				if (check(cache))
				{
					q.push(cache);
					visited[cache.x][cache.y] = true;
				}
			}
		}
	}
	return;
}

bool check(point p)
{
	if (p.x < 0 || p.y < 0 || p.x >= m || p.y >= n)
		return false;
	if (visited[p.x][p.y] == true)
		return false;
	if (board[p.x][p.y] == '*')
		return false;
	return true;
}
