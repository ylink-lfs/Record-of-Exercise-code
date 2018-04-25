#include <iostream>
#include <cstdlib>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;

struct program
{
	int lower_b;
	int upper_b;
};

bool cmp(program, program);

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	program manyprogram[100];
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> manyprogram[i].lower_b >> manyprogram[i].upper_b;
		}
		int counter = 1;
		sort(manyprogram, manyprogram + n, cmp);
		program judger = manyprogram[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			if (manyprogram[i].upper_b <= judger.lower_b)
			{
				judger = manyprogram[i];
				counter++;
			}
		}
		cout << counter << '\n';
	}

	return 0;
}

bool cmp(program a, program b)
{
	if (a.lower_b != b.lower_b)
		return a.lower_b < b.lower_b;
	else
		return a.upper_b > b.upper_b;
}