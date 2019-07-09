#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct term
{
	int exp;
	double base;
	term(const int e, const double b) : exp(e), base(b) {}
};

class polynomial
{
private:
	vector<term> body;
public:
	polynomial() {}
	polynomial(const vector<term>& v) : body(v) {}
	void add_term(const term& t) { body.push_back(t); }
	const vector<term>& poly_body() const { return body; }
	friend polynomial operator+(const polynomial& p1, const polynomial& p2);
	polynomial operator*(const term& t);
	polynomial operator*(const polynomial& p);
};

polynomial operator+(const polynomial & p1, const polynomial & p2)
{
	auto it1 = p1.poly_body().cbegin(), it2 = p2.poly_body().cbegin();
	vector<term> res;
	while (it1 < p1.poly_body().cend() && it2 < p2.poly_body().cend())
	{
		if (it1->exp > it2->exp)
		{
			res.push_back(*it1++);
		}
		else if (it1->exp < it2->exp)
		{
			res.push_back(*it2++);
		}
		else
		{
			double b = it1->base + it2->base;
			const double eps = 1e-9;
			if (b >= eps || b <= -eps)
			{
				double e = it1->exp;
				res.push_back(term(e, b));
			}
			it1++;
			it2++;
		}
	}
	while (it1 < p1.poly_body().cend())
	{
		res.push_back(*it1++);
	}
	while (it2 < p2.poly_body().cend())
	{
		res.push_back(*it2++);
	}
	return polynomial(res);
}

polynomial polynomial::operator*(const term & t)
{
	vector<term> res;
	for (auto it = body.cbegin(); it < body.cend(); it++)
	{
		double b = it->base;
		int e = it->exp;
		e += t.exp;
		b *= t.base;
		res.push_back(term(e, b));
	}
	return polynomial(res);
}

polynomial polynomial::operator*(const polynomial & p)
{
	polynomial res((*this) * p.body[0]);
	for (int i = 1; i < p.body.size(); i++)
	{
		polynomial t = (*this) * p.body[i];
		res = res + t;
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	polynomial p1, p2;
	int k1, k2;
	while (cin >> k1)
	{
		for (int i = 0; i < k1; i++)
		{
			int e;
			double b;
			cin >> e >> b;
			p1.add_term(term(e, b));
		}
		cin >> k2;
		for (int i = 0; i < k2; i++)
		{
			int e;
			double b;
			cin >> e >> b;
			p2.add_term(term(e, b));
		}
		polynomial res = p1 * p2;
		cout << res.poly_body().size() << ' ';
		cout << fixed;
		cout.precision(1);
		for (auto it = res.poly_body().cbegin(); it < res.poly_body().cend(); it++)
		{
			cout << it->exp << ' ';	
			cout << it->base;
			if (it + 1 == res.poly_body().cend())
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