#include <list>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const double eps = 1e-8;

inline bool equ(double d1, double d2) { return fabs(d1 - d2) < eps; }

struct polynomial_term
{
	int exponent;
	double factor;
	polynomial_term(const int exp, const double fact) : exponent(exp), factor(fact) {}
	friend ostream& operator<<(ostream& os, const polynomial_term& term)
	{
		return os << term.exponent << ' ' << term.factor;
	}
};

using polynomial = list<polynomial_term>;

polynomial add_polynomial(const polynomial& p1, const polynomial& p2);
void read_polynomial(polynomial& p, int term_num, istream& ist = cin);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int count1, count2;
	while (cin >> count1)
	{
		polynomial p1;
		read_polynomial(p1, count1);
		cin >> count2;
		polynomial p2;
		read_polynomial(p2, count2);
		polynomial res = add_polynomial(p1, p2);
		cout << res.size() << (res.size() != 0 ? ' ' : '\0');
		cout.setf(ios_base::fixed);
		cout.precision(1);
		for (auto it = res.begin(); it != res.end(); it++)
		{
			cout << *it;
			auto assist_it = it;
			assist_it++;
			if (assist_it == res.end())
			{
				cout << '\n';
			}
			else
			{
				cout << ' ';
			}
		}
	}
	return 0;
}

polynomial add_polynomial(const polynomial& p1, const polynomial& p2)
{
	polynomial poly;
	auto it1 = p1.begin();
	auto it2 = p2.begin();
	while (it1 != p1.end() && it2 != p2.end())
	{
		if (it1->exponent > it2->exponent)
		{
			poly.push_back(*it1++);
		}
		else if (it1->exponent < it2->exponent)
		{
			poly.push_back(*it2++);
		}
		else
		{
			if (!equ(it1->factor + it2->factor, 0.0))
			{
				poly.push_back(polynomial_term(it1->exponent, it1->factor + it2->factor));
			}
			it1++;
			it2++;
		}
	}
	if (it1 != p1.end())
	{
		while (it1 != p1.end())
		{
			poly.push_back(*it1++);
		}
	}
	else if (it2 != p2.end())
	{
		while (it2 != p2.end())
		{
			poly.push_back(*it2++);
		}
	}
	return poly;
}

void read_polynomial(polynomial& p, int term_num, istream& ist)
{
	if (!p.empty())
	{
		p.clear();
	}
	for (int i = 0; i < term_num; i++)
	{
		int exp;
		double fac;
		ist >> exp >> fac;
		p.push_back(polynomial_term(exp, fac));
	}
}
