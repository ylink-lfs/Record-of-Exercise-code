#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

unsigned dp[40] = { 0 };

int calc_fib(int n)
{
	if (n == 0 || n == 1)
		return n;
	else if (dp[n])
		return dp[n];
	else
	{
		return dp[n] = calc_fib(n - 1) + calc_fib(n - 2);
	}
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		cout << calc_fib(n) << endl;
	}
	return 0;
}