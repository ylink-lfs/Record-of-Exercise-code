#include <iostream>
#include <algorithm>
#include <array>
#include <cstdlib>

using namespace std;

const size_t table_size = 2000000;

array<int, table_size> prime_num;
size_t curn = 0;

array<bool, table_size> prime_table;

void etho();

int main(void)
{
	etho();
	int n;
	while (cin >> n)
	{
		int pair_count = 0;
		for (int i = 0; i < curn - 1; i++)
		{
			if (prime_num[i] >= n)
				break;
			if (prime_num[i + 1] - prime_num[i] == 2 && prime_num[i + 1] <= n)
				pair_count++;
		}
		cout << pair_count << '\n';
	}

	return 0;
}

void etho()
{
	fill(prime_table.begin(), prime_table.end(), true);
	prime_table[0] = prime_table[1] = false;
	for (size_t i = 2; i < table_size; i++)
	{
		if (prime_table[i])
		{
			prime_num[curn++] = i;
			for (size_t j = i * i; j < table_size; j += i)
			{
				prime_table[j] = false;
			}
		}
	}

}