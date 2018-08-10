#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

long long calc_mult(const vector<long long>& v);

int main(void)
{
	vector<int> res_vec;
	int n;
	cin >> n;
	int sq_n = sqrt(n);

	for (int i = 2; i <= sq_n; i++)
	{
		vector<int> tmp_vec;
		long long mult_val = 1;
		for (long long j = i; j <= sq_n && n % mult_val == 0; j++)
		{
			if (static_cast<long long>(n) % (mult_val * j) == 0)
			{
				tmp_vec.push_back(j);
				mult_val *= j;
			}
			else
			{
				break;
			}
		}
		if (res_vec.empty())
		{
			res_vec = tmp_vec;
			continue;
		}
		else if (tmp_vec.empty())
		{
			continue;
		}
		else if (res_vec.size() < tmp_vec.size())
		{
			res_vec = tmp_vec;
			continue;
		}
	}
	if (res_vec.empty())
	{
		res_vec.push_back(n);
	}

	cout << res_vec.size() << '\n';
	for (int i = 0; i < res_vec.size(); i++)
	{
		cout << res_vec[i];
		if (i == res_vec.size() - 1)
			cout << '\n';
		else
			cout << '*';
	}


	return 0;
}

long long calc_mult(const vector<long long>& v)
{
	long long res = 1;
	for (const auto& val : v)
		res *= val;
	return res;
}