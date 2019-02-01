#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

short dp[5010][5010];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string source;
	string s;
	unordered_map<int, int> mp;
	while (getline(cin, source))
	{
		for (int i = 0; i < source.size(); i++)
		{
			if (ispunct(source[i]) || isspace(source[i]))
			{
				continue;
			}
			else
			{
				if (isdigit(source[i]))
				{
					s.push_back(source[i]);
				}
				else
				{
					s.push_back(tolower(source[i]));
				}
				mp.insert(make_pair(mp.size(), i));
			}
		}
		int par_len = 1;
		int res_left, res_right;
		res_left = res_right = 0;
		for (int i = 0; i < s.size(); i++)
		{
			dp[i][i] = 1;
			if (i < s.size() - 1 && s[i] == s[i + 1])
			{
				par_len = 2;
				dp[i][i + 1] = 1;
				if (res_right - res_left + 1 < 2)
				{
					res_left = i;
					res_right = i + 1;
				}
			}
		}
		for (int cur_len = 3; cur_len <= s.size(); cur_len++)
		{
			for (int i = 0; i + cur_len - 1 < s.size(); i++)
			{
				if (s[i] == s[i + cur_len - 1] && dp[i + 1][i + cur_len - 2] == 1)
				{
					par_len = cur_len;
					dp[i][i + cur_len - 1] = 1;
					if (res_right - res_left + 1 < cur_len)
					{
						res_left = i;
						res_right = i + cur_len - 1;
					}
				}
			}
		}
		for (int i = mp[res_left]; i <= mp[res_right]; i++)
		{
			cout << source[i];
		}
		cout << '\n';
		s.clear();
		mp.clear();
		for (int i = 0; i < 5010; i++)
		{
			for (int j = 0; j < 5010; j++)
			{
				dp[i][j] = 0;
			}
		}
	}
	return 0;
}