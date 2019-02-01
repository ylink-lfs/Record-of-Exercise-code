#include <iostream>
#include <string>

using namespace std;

short dp[1010][1010];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s))
	{		
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
		cout << par_len << '\n';
		for (int i = 0; i < 1010; i++)
		{
			for (int j = 0; j < 1010; j++)
			{
				dp[i][j] = 0;
			}
		}
	}
	return 0;
}