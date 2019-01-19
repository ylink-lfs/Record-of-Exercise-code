#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

const int maxn = 10010;

struct dpst
{
	int maxsum;
	int lower_bound;
	int upper_bound;
};

dpst dp[maxn];
int num[maxn];
bool neg_flag = true;

int solve_sequence(int n);

int main(void)
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
			if (num[i] >= 0)
				neg_flag = false;
		}

		if (neg_flag)
		{
			cout << "0 " << num[0] << ' ' << num[n - 1] << '\n';
		}
		else
		{
			int res_index = solve_sequence(n);
			cout << dp[res_index].maxsum << ' ' << num[dp[res_index].lower_bound] 
				<< ' ' << num[dp[res_index].upper_bound] << '\n';
		}

		neg_flag = true;
	}


	return 0;
}

int solve_sequence(int n)
{
	dp[0] = { num[0], 0, 0 };
	int maxindex = 0;

	for (int i = 1; i < n; i++)
	{
		int select = max(num[i], dp[i - 1].maxsum + num[i]);
		if (select == num[i])
		{
			dp[i].maxsum = num[i];
			dp[i].lower_bound = dp[i].upper_bound = i;
		}
		else
		{
			dp[i].maxsum = num[i] + dp[i - 1].maxsum;
			dp[i].lower_bound = dp[i - 1].lower_bound;
			dp[i].upper_bound = i;
		}
		if (dp[maxindex].maxsum < dp[i].maxsum)
			maxindex = i;
	}
	return maxindex;
}