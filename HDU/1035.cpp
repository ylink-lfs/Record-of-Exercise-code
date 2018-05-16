#include <iostream>
#include <cstring>

using namespace std;

struct point
{
	int x, y;
};

char maze[12][12];
int arrived[12][12];

int line, colomn;
int current_step;
int before_step, loop_step;

point start_p = { 0, -100 };

void dfs(point current_point);
bool is_overstep(point p);
bool is_went_twice(point p);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> line >> colomn >> start_p.y && line != 0)
	{
		start_p.y--;
		while (cin.get() != '\n')
			continue;
		memset(arrived, 0, sizeof(int) * 12 * 12);
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < colomn; j++)
			{
				cin >> maze[i][j];
			}
			while (cin.get() != '\n')
				continue;
		}
		current_step = 0;
		before_step = loop_step = -1;
		dfs(start_p);
		if (loop_step > 0)
		{
			cout << before_step << " step(s) before a loop of " << loop_step << " step(s)\n";
		}
		else
		{
			cout << current_step << " step(s) to exit\n";
		}
	}
	return 0;
}

void dfs(point p)
{
	if (is_overstep(p))
		return;
	if (is_went_twice(p))
	{
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < colomn; j++)
			{
				if (arrived[i][j] == 1)
					before_step++;
				if (arrived[i][j] == 2)
					loop_step++;
			}
		}
		before_step++;
		loop_step++;
		return;
	}
	current_step++;
	arrived[p.x][p.y]++;
	switch (maze[p.x][p.y])
	{
		point cache;
	case 'N': cache.x = p.x - 1; cache.y = p.y; dfs(cache); break;
	case 'S': cache.x = p.x + 1; cache.y = p.y; dfs(cache); break;
	case 'E': cache.x = p.x; cache.y = p.y + 1; dfs(cache); break;
	case 'W': cache.x = p.x; cache.y = p.y - 1; dfs(cache); break;
	}
	return;
}

bool is_overstep(point p)
{
	if (p.x < 0 || p.y < 0 || p.x >= line || p.y >= colomn)
		return true;
	return false;
}

bool is_went_twice(point p)
{
	if (arrived[p.x][p.y] == 2)
		return true;
	return false;
}
