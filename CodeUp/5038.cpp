#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int count_50, count_20, count_10, count_5, count_1;
	while (cin >> n)
	{
		count_50 = count_20 = count_10 = count_5 = count_1 = 0;
		while (n - 50 >= 0)
		{
			n -= 50;
			count_50++;
		}
		while (n - 20 >= 0)
		{
			n -= 20;
			count_20++;
		}
		while (n - 10 >= 0)
		{
			n -= 10;
			count_10++;
		}
		while (n - 5 >= 0)
		{
			n -= 5;
			count_5++;
		}
		while (n - 1 >= 0)
		{
			n -= 1;
			count_1++;
		}
		bool printed = false;
		if (count_50)
		{
			cout << "50*" << count_50;
			printed = true;
		}
		if (count_20)
		{
			if (printed)
			{
				cout << '+' << "20*" << count_20;
			}
			else
			{
				cout << "20*" << count_20;
				printed = true;
			}
		}
		if (count_10)
		{
			if (printed)
			{
				cout << '+' << "10*" << count_10;
			}
			else
			{
				cout << "10*" << count_10;
				printed = true;
			}
		}
		if (count_5)
		{
			if (printed)
			{
				cout << '+' << "5*" << count_5;
			}
			else
			{
				cout << "5*" << count_5;
				printed = true;
			}
		}
		if (count_1)
		{
			if (printed)
			{
				cout << '+' << "1*" << count_1;
			}
			else
			{
				cout << "1*" << count_1;
			}
		}
		cout << '\n';
	}
	return 0;
}