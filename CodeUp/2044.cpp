#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;

int container[40];

int counter(int sum, int n);

int main(void)
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> container[i];
		}
		cout << counter(40, n);
		cout << '\n';
	}
	system("pause");
	return 0;
}

int counter(int sum, int n)
{
	if (sum == 0)
		return 1;
	else if (n < 0)
		return 0;
	else
		return counter(sum, n - 1) + counter(sum - container[n - 1], n - 1);
}