//输出控制真是鸡飞狗跳...
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int number);
bool check_v(vector<int>& v);
bool mid_check(vector<int>& v);
void dfs(vector<int>& res, vector<int>& src);

bool check[25];
bool in_case;
int range;
static int line_count = 1;

int main(void)
{
	while (cin >> range)
	{
		vector<int> res;
		vector<int> src;
		memset(check, false, sizeof(bool) * 20);
		res.push_back(1);
		in_case = false;
		for (int i = 2; i <= range; i++)
		{
			src.push_back(i);
		}
		dfs(res, src);
		cout << '\n';
	}
	return 0;
}

bool is_prime(int n)
{
	if (n <= 1)
		return false;
	else if (n == 2)
		return true;
	else if (n % 2 == 0)
		return false;
	else
	{
		for (int i = 3; i <= sqrt(n); i += 2)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}
}

//at the beginning, res already contain 1, src contain numbers from 2
void dfs(vector<int>& res, vector<int>& src)
{
	if (res.size() == range)
	{		
		if (check_v(res))
		{
			if (!in_case)
			{
				cout << "Case " << line_count++ << ":\n";
			}
			in_case = true;
			for (int i = 0; i < res.size(); i++)
			{
				cout << res[i];
				if (i == res.size() - 1)
					cout << '\n';
				else
					cout << ' ';
			}
		}
		return;
	}
	for (int i = 0; i < src.size(); i++)
	{
		if (check[src[i]] == false)  //elem doesn't exist in res, insert it
		{
			res.push_back(src[i]);
			check[src[i]] = true;
			if (res.size() == 1 || is_prime(res[res.size() - 1] + res[res.size() - 2]))
			{
				dfs(res, src);				
			}
			check[src[i]] = false;
			res.erase(res.end() - 1);
		}
	}
}

bool check_v(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (!is_prime(v[i] + v[(i + 1) % v.size()]))
			return false;
	}
	return true;
}

bool mid_check(vector<int>& v)
{
	for (int i = 0; i < v.size() - 2; i++)
	{
		if (!is_prime(v[i] + v[i + 1]))
			return false;
	}
	return true;
}
