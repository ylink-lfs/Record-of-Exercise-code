#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void print(int counter, int n);

int space_table[10] = { 0,2,4,6,8,10,12,14,16,18 };

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int case_count;
	cin >> case_count;
	while (case_count--)
	{
		int n;
		cin >> n;
		print(0, n);
	}
	return 0;
}

void print(int counter, int n)
{
	if (counter >= n)
		return;
	else
	{
		vector<int> fib_container;
		fib_container.push_back(0);
		fib_container.push_back(1);
		for (int i = 2; i < 2 * counter + 1; i++)
			fib_container.push_back(fib_container[i - 1] + fib_container[i - 2]);

		for (int k = 0; k < space_table[n - 1] - counter * 2; k++)
			cout << ' ';
		for (int i = 0; i < 2 * counter + 1; i++)
		{

			if (i == 2 * counter)
				cout << fib_container[i] << '\n';
			else
				cout << fib_container[i] << ' ';
		}

		print(counter + 1, n);
	}
}