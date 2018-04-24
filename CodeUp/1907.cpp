#include <iostream>

int calculate(int);

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	int res;
	while (std::cin >> n)
	{
		res = calculate(n);
		std::cout << res << '\n';
	}
	return 0;
}

int calculate(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return calculate(n - 1) + calculate(n - 2);
}