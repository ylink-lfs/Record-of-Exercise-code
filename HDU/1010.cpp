//31次 wa、tle...哀民生之多艰...
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

inline int myabs(int x) { return x >= 0 ? x : -x; }

char maze[8][8];
bool g_flag = false;
int stx, sty, enx, eny;
int m, n, t;
int wall_count;

void dfs(int x, int y, int ct);

int main(void)
{
	while (scanf("%d%d%d", &n, &m, &t) == 3 && n != 0)
	{
		memset(maze, 'X', sizeof(char) * 8 * 8);
		while (getchar() != '\n')
			continue;
		wall_count = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &maze[i][j]);
				
				if (maze[i][j] == 'S')
				{
					stx = i;
					sty = j;
				}
				else if (maze[i][j] == 'D')
				{
					enx = i;
					eny = j;
				}
				else if (maze[i][j] == 'X')
				{
					wall_count++;
				}
			}
			while (getchar() != '\n')
				continue;
		}
		int short_dst = myabs(enx - stx) + myabs(eny - sty);
		if (n * m - wall_count < t || (myabs(short_dst - t) & 1) != 0)
		{
			printf("NO\n");
			continue;
		}
		g_flag = false;
		dfs(stx, sty, t);
		if (g_flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}

void dfs(int x, int y, int ct)
{
	if (maze[x][y] == 'X' || maze[x][y] == 'P')
		return;
	if (ct == 0)
	{
		if (maze[x][y] == 'D')
		{
			g_flag = true;
		}
		return;
	}
	int rest_step = myabs(x - enx) + myabs(y - eny);
	int rest_dst = ct;
	if ((rest_step & 1) != (rest_dst & 1))
		return;
	char pre_ch = maze[x][y];
	maze[x][y] = 'P';
	if (!g_flag) dfs(x + 1, y, ct - 1);
	if (!g_flag) dfs(x, y + 1, ct - 1);
	if (!g_flag) dfs(x - 1, y, ct - 1);
	if (!g_flag) dfs(x, y - 1, ct - 1);
	maze[x][y] = pre_ch;

	return;
}
