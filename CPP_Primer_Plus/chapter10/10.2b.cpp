#include <string>
#include <cstring>
#include <iostream>
#include "10.2a.h"

using std::cout;
using std::endl;

Person::Person(const string& ln, const char* fn)
{
	lname = ln;
	strncpy(fname, fn, LIMIT);
}
void Person::Show() const
{
	cout << fname << ' ' << lname << endl;
}

void Person::FormalShow() const
{
	cout << lname << ' ' << fname << endl;
}
