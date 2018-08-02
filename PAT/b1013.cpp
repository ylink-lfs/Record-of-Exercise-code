#include <iostream>
#include <algorithm>
#include <array>
#include <cstdlib>

using namespace std;

const size_t table_size = 500000;

array<int, table_size> prime_num;
int curn = 0;

array<bool, table_size> prime_table;

void etho();

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	etho();
	int m, n;
	while (cin >> m >> n)
	{
		m--;
		n--;
		for (int i = m; i <= n; i++)
		{
			cout << prime_num[i];
			if ((i + 1 - m) % 10 == 0 || i == n)
				cout << '\n';
			else
				cout << ' ';
		}
	}

	return 0;
}

void etho()
{
	fill(prime_table.begin(), prime_table.end(), true);
	prime_table[0] = prime_num[1] = false;
	prime_table[2] = true;
	for (size_t i = 2; i < table_size; i++)
	{
		if (prime_table[i])
		{
			prime_num[curn++] = i;
			for (size_t j = i * i; j < table_size; j += i)
				prime_table[j] = false;
		}
	}
}