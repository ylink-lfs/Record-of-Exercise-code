#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cstdlib>

using namespace std;

const int max_possible_table_size = 10010;

array<bool, max_possible_table_size> prime_table;

void eratos();

class hash_table
{
public:
	struct table_elem
	{
		int val;
		bool occupied;
		table_elem(int v = 0, bool oc = false) : val(v), occupied(oc) {}
	};
private:
	int hash_prime;
	vector<table_elem> table;
public:
	hash_table(int table_size) : hash_prime(table_size), table(table_size) {}
	int insert(int elem);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	eratos();
	int msize, n;
	while (cin >> msize >> n)
	{
		while (prime_table[msize] == false)
			msize++;
		hash_table opt_table(msize);
		for (int i = 0; i < n; i++)
		{
			int tmp_n;
			cin >> tmp_n;

			int pos;
			if ((pos = opt_table.insert(tmp_n)) >= 0)
			{
				cout << pos;
			}
			else
			{
				cout << '-';
			}
			if (i == n - 1)
				cout << '\n';
			else
				cout << ' ';
		}
	}

	return 0;
}

void eratos()
{
	fill(prime_table.begin(), prime_table.end(), true);
	prime_table[0] = prime_table[1] = false;
	prime_table[2] = true;
	for (size_t i = 2; i < prime_table.size(); i++)
	{
		if (prime_table[i])
		{
			for (size_t j = i * i; j < prime_table.size(); j += i)
			{
				prime_table[j] = false;
			}
		}
	}
}

int hash_table::insert(int elem)
{
	int base_insert_place = elem % hash_prime;
	int increment_num = 0;
	int actual_insert_place;
	do
	{
		actual_insert_place = (base_insert_place + increment_num * increment_num) % hash_prime;
		increment_num++;
	} while (table[actual_insert_place].occupied == true && increment_num < hash_prime);
	if (table[actual_insert_place].occupied == false)
	{
		table[actual_insert_place].occupied = true;
		return actual_insert_place;
	}
	else
	{
		return -1;
	}
}