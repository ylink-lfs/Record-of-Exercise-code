#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int maxn = 1010;
int num[maxn], dp[maxn];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		int res = -1;
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				//num[j] < num[i]?
				//dp[i] <= dp[j] + 1?
				if (num[j] <= num[i] && dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;					
				}
			}
			//res = max(dp[i], 1)?
			res = max(dp[i], res);
		}
		cout << res << '\n';
	}
	return 0;
}