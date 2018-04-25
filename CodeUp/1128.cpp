#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using std::cin;
using std::cout;
using std::ios_base;

const double eps = 1e-8;

inline bool Less(double a, double b) { return a - b < -eps; }

inline bool LessEqual(double a, double b) { return a - b < eps; }

inline bool Equal(double a, double b) { return fabs(a - b) < eps; }

double price_calculate(int);

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.setf(std::ios_base::fixed);
	cout.unsetf(ios_base::showpoint);

	int distance;
	double res;
	int times;
	int temp;

	while (cin >> distance && distance > 0)
	{
		if (distance <= 13)
		{
			res = price_calculate(distance);
		}
		else
		{
			double temp_price;
			temp = distance % 8;
			times = distance / 8;
			if (temp < 5)
				temp_price = temp * 2.4;
			else
				temp_price = price_calculate(temp);
			double repeat_cost = price_calculate(8);
			res = temp_price + repeat_cost * times;
		}
		if (Equal(res, floor(res)))
		{
			cout.precision(0);			
		}
		else
		{
			cout.precision(1);
		}
		cout << res << '\n';
	}

	return 0;
}

double price_calculate(int n)
{
	if (n == 0)
		return 0;
	else if (n > 0 && n <= 4)
		return 10;
	else if (n > 4 && n <= 8)
		return 2 * n + 2;
	else
		return 2.4 * n - 1.2;
}