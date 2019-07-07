#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TIME
{
	int h;
	int m;
	int s;
public:
	TIME(const int h_, const int m_, const int s_) : h(h_), m(m_), s(s_) {}
	friend bool operator<(const TIME& t1, const TIME& t2)
	{
		if (t1.h != t2.h)
		{
			return t1.h < t2.h;
		}
		else if (t1.m != t2.m)
		{
			return t1.m < t2.m;
		}
		else
		{
			return t1.s <= t2.s;
		}
	}
};

class record
{
public:
	string id;
	TIME in_TIME;
	TIME out_TIME;
	record(const string& id_, const TIME& t1, const TIME& t2) : id(id_), in_TIME(t1), out_TIME(t2) {}
};

TIME trim_TIME(const string& s)
{
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));
	int sec = stoi(s.substr(6, 2));
	return TIME(h, m, sec);
}

bool come_first(const record& r1, const record& r2)
{
	return r1.in_TIME < r2.in_TIME;
}

bool leave_first(const record& r1, const record& r2)
{
	return !(r1.out_TIME < r2.out_TIME);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		vector<record> r;
		for (int i = 0; i < n; i++)
		{
			string s_t1, s_t2, id;
			cin >> id >> s_t1 >> s_t2;
			TIME t1(trim_TIME(s_t1)), t2(trim_TIME(s_t2));
			r.push_back(record(id, t1, t2));
		}
		sort(r.begin(), r.end(), come_first);
		cout << r[0].id << ' ';
		sort(r.begin(), r.end(), leave_first);
		cout << r[0].id << '\n';
	}
	return 0;
}