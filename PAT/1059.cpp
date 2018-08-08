#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

array<bool, 8000000> prime_table;
void etho();

struct fac
{
	int val;
	int count;
};

class expression
{
private:
	vector<fac> expr;
	long tar_val;
public:
	expression(const vector<fac>& exp, long tar) : expr(exp), tar_val(tar) {}
	friend ostream& operator<<(ostream& os, const expression& ex)
	{
		os << ex.tar_val << '=';
		for (int i = 0; i < ex.expr.size(); i++)
		{
			os << ex.expr[i].val;
			if (ex.expr[i].count > 1)
			{
				os << '^' << ex.expr[i].count;
			}
			if (i < ex.expr.size() - 1)
			{
				os << '*';
			}
		}
		return os;
	}
};

int main(void)
{
	etho();
	long n;
	while (cin >> n)
	{
		long ori_val = n;
		vector<fac> expr_src;
		int sq_n = sqrt(static_cast<double>(n));
		for (int i = 2; i <= sq_n; i++)
		{
			if (!prime_table[i])
				continue;
			else
			{
				if (n % i == 0)
				{
					fac tmp;
					tmp.val = i;
					tmp.count = 0;
					while (n % i == 0)
					{
						tmp.count++;
						n /= i;
					}
					expr_src.push_back(tmp);
				}			
			}
		}
		if (n != 1)
		{
			fac tmp;
			tmp.val = n;
			tmp.count = 1;
			expr_src.push_back(tmp);
		}
		expression output_exp(expr_src, ori_val);
		if (ori_val == 1)
		{
			cout << "1=1" << endl;
			//I don't think is a good design, but only in this way can I pass the problem, the reason is that 1 is not a prime.
		}
		else
		{
			cout << output_exp << endl;
		}	
	}

	return 0;
}

void etho()
{
	fill(prime_table.begin(), prime_table.end(), true);
	prime_table[0] = prime_table[1] = false;
	prime_table[2] = true;
	for (int i = 2; i < prime_table.size(); i++)
	{
		if (prime_table[i])
		{
			for (int j = i * 2; j < prime_table.size(); j += i)
			{
				prime_table[j] = false;
			}
		}
	}
	
}