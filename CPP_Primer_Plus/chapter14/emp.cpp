#include <iostream>
#include "emp.h"

using std::cin;
using std::cout;
using std::endl;

abstr_emp::abstr_emp() : fname("n/a"), lname("n/a"), job("n/a")
{}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j) : fname(fn), lname(ln), job(j)
{}

void abstr_emp::ShowAll() const
{
	cout << "Name: " << fname << ' ' << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Please enter new full name: ";
	cin >> fname >> lname;
	cout << "Please enter new job: ";
	cin >> job;
}

abstr_emp::~abstr_emp()
{}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	return os << "Name: " << e.fname << ' ' << e.lname << '\t' << "Job: " << e.job;
}

employee::employee() : abstr_emp()
{}

employee::employee(const string& fn, const string& ln, const string& j) : abstr_emp(fn, ln, j)
{}

void employee::ShowAll() const
{
	cout << "Position: General Employee\n";
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(-1)
{}

manager::manager(const string& fn, const string& ln, const string& j, int ico) : abstr_emp(fn, ln, j),
	inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico)
{}

manager::manager(const manager& m) : abstr_emp(m)
{
	inchargeof = m.InChargeOf();
}

void manager::ShowAll() const
{
	cout << "Position: Manager\n";
	abstr_emp::ShowAll();
	cout << "In charge of " << inchargeof << " people\n";
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Please update the inchargeof number: ";
	cin >> inchargeof;
}

fink::fink() : abstr_emp()
{}

fink::fink(const string& fn, const string& ln, const string& j, const string& rpo) : abstr_emp(fn, ln, j),
	reportsto(rpo)
{}

fink::fink(const abstr_emp& e, const string& rpo) : abstr_emp(e), reportsto(rpo)
{}

fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = e.ReportsTo();
}

void fink::ShowAll() const
{
	cout << "Position: Fink\n";
	abstr_emp::ShowAll();
	cout << "Reports to demon " << reportsto << '\n';
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Please update the reportsto field: ";
	cin >> reportsto;
}

highfink::highfink() : abstr_emp(), fink(), manager()
{}

highfink::highfink(const string& fn, const string& ln, const std::string& j, const string& rpo, int ico) :
	abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)
{}

highfink::highfink(const abstr_emp& e, const string& rpo, int ico) : abstr_emp(e), fink(e, rpo), manager(e, ico)
{}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), fink(f), manager(f, ico)
{}

highfink::highfink(const manager& m, const string& rpo) : abstr_emp(m), fink(m, rpo), manager(m)
{}

highfink::highfink(const highfink& h) : abstr_emp(h), fink(h), manager(h)
{}

void highfink::ShowAll() const
{
	cout << "Position: High Fink\n";
	abstr_emp::ShowAll();
	cout << "In charge of " << InChargeOf() << " people, and reports to demon " << ReportsTo() << '\n';
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Please update inchargeof number: ";
	cin >> InChargeOf();
	cout << "Please update reportsto member: ";
	cin >> ReportsTo();
}

/*
1.
从语义上说，每个人都具有独立性，将一个人对象赋给另一个人对象并没有实际意义

2.
不同的职位成员需要显示和改变的信息不同

3.
为了使第三代子类highfink只包含一个abstr_emp基类对象，符合类的目标语义

4.
highfink类从三个基类公有继承而来，已经继承了三个父类的字段，从而不需要自己的字段

5.
子类使用该友元函数时会被自动cast到基类

6.
编译错误。abstr_emp为抽象基类，无法被实例化
*/
