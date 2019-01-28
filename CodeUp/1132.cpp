#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

char s1[110];
char s2[110];
int dp[110][110];

int main(void)
{
	while (scanf("%s%s", s1, s2) == 2)
	{
		int s1_len = strlen(s1);
		int s2_len = strlen(s2);

		//Notice potential index outrange
		for (int i = 1; i <= s1_len; i++)
		{
			for (int j = 1; j <= s2_len; j++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[s1_len][s2_len] << '\n';
	}
	return 0;
}