#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <array>
#include <cstdlib>

using namespace std;

const int table_size = 100005;

array<bool, table_size> prime_table;

void erato();
string get_digits(int n, const int dec);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	erato();
	int n, dec;
	while (cin >> n && n > 0)
	{
		cin >> dec;
		if (prime_table[n] == false)
		{
			cout << "No\n";
		}
		else
		{
			string digit(get_digits(n, dec));
			reverse(digit.begin(), digit.end());
			int n1 = stoi(digit, 0, dec);
			if (prime_table[n1])
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}

	system("pause");
	return 0;
}

void erato()
{
	fill(prime_table.begin(), prime_table.end(), true);
	prime_table[0] = prime_table[1] = false;
	prime_table[2] = true;
	for (size_t i = 2; i < table_size; i++)
	{
		if (prime_table[i])
		{
			for (size_t j = i * i; j < table_size; j += i)
			{
				prime_table[j] = false;
			}
		}
	}
}

string get_digits(int n, const int dec)
{
	string s;
	while (n)
	{
		s.insert(0, 1, '0' + n % dec);
		n /= dec;
	}
	return s;
}