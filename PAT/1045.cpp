#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

const int maxlength = 10010;
const int max_color_variance = 210;

//Use [colorid] [stage] format
int color_precedence[max_color_variance];

vector<int> original_strip;
int dp[maxlength];
bool color_exists[max_color_variance];

int main(void)
{
	int color_variance;
	while (cin >> color_variance)
	{
		int favoriate_variance;
		cin >> favoriate_variance;
		for (int i = 0; i < favoriate_variance; i++)
		{
			int colorid;
			cin >> colorid;
			color_precedence[colorid] = i;
			color_exists[colorid] = true;
		}

		int strip_length;
		cin >> strip_length;
		for (int i = 0; i < strip_length; i++)
		{
			int colorid;
			cin >> colorid;
			if (color_exists[colorid])
			{
				original_strip.push_back(colorid);
			}
		}
		strip_length = original_strip.size();

		int res = -1;
		for (int i = 0; i < strip_length; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (color_precedence[original_strip[j]] <= color_precedence[original_strip[i]] 
					&& dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
				}
			}
			res = max(res, dp[i]);
		}
		cout << res << '\n';

		fill(color_exists, color_exists + max_color_variance, false);
	}
	return 0;
}

//LCS Solution
//#include <iostream>
//#include <algorithm>
//#include <cstdlib>
//
//int dp[210][10010];
//int s1[210];
//int s2[10010];
//
//using namespace std;
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int tot_colors;
//	cin >> tot_colors;
//	int color_count;
//	cin >> color_count;
//	for (int i = 0; i < color_count; i++)
//	{
//		cin >> s1[i];
//	}
//	int stripe_len;
//	cin >> stripe_len;
//	for (int i = 0; i < stripe_len; i++)
//	{
//		cin >> s2[i];
//	}
//	for (int i = 0; i < color_count; i++)
//	{
//		for (int j = 0; j < stripe_len; j++)
//		{
//			if (s1[i] == s2[j])
//			{
//				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]) + 1;
//			}
//			else
//			{
//				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
//			}
//		}
//	}
//	cout << dp[color_count][stripe_len] << '\n';
//	return 0;
//}
