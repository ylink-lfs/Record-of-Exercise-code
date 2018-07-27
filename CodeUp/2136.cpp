#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;

int GCD(const int a, const int b) { return b == 0 ? a : GCD(b, a % b); }
int LCM(const int a, const int b) { return a / GCD(a, b) * b; }
int LCM(const vector<int>::iterator left_it, const vector<int>::iterator right_it);

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> src;
	int case_count;
	cin >> case_count;
	while (case_count--)
	{
		int elem_count;
		cin >> elem_count;
		src.resize(elem_count);
		for (int i = 0; i < elem_count; i++)
		{
			cin >> src[i];
		}
		int biggest_lcm;
		if (src.size() == 1)
		{
			biggest_lcm = src[0];
		}
		else
		{			
			if (elem_count % 1 != 0)
				src.push_back(1);
			biggest_lcm = LCM(src.begin(), src.end());
		}
		cout << biggest_lcm << '\n';

		src.clear();
	}

	return 0;
}

int LCM(const vector<int>::iterator left_it, const vector<int>::iterator right_it)
{
	if (right_it - left_it == 2)
	{
		return LCM(*left_it, *(right_it - 1));
	}
	else
	{
		return LCM(LCM(left_it, left_it + (right_it - left_it) / 2), LCM(left_it + (right_it - left_it) / 2, right_it));
	}
}