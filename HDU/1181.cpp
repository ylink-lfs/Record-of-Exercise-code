//stack overflow without using "check"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(char target, vector<string>& src);
bool g_flag;

unordered_set<string> check;

int main(void)
{
	vector<string> src;
	string cache;
	while (cin >> cache)
	{
		src.push_back(cache);
		if (cache[0] != '0' && cache[0] != -1)
		{
			while (cin >> cache && cache[0] != '0')
				src.push_back(cache);
		}
		else if (cache[0] == -1)
			break;
		
		g_flag = 0;
		dfs('b', src);
		if (g_flag)
			cout << "Yes.\n";
		else
			cout << "No.\n";

		src.clear();
		check.clear();
	}
	return 0;
}

void dfs(char target, vector<string>& src)
{
	for (auto it = src.begin(); it != src.end(); it++)
	{
		if (check.find(*it) != check.end())
			continue;
		if ((*it)[0] == target)
		{
			
			int len = (*it).size();
			if ((*it)[len - 1] == 'm')
			{
				g_flag = true;
				return;
			}
			else
			{
				check.insert(*it);
				dfs((*it)[len - 1], src);
			}
		}
		else
			continue;
	}
	return;
}
