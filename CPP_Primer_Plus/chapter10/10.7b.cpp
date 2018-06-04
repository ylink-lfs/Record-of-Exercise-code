#include <iostream>
#include <cstring>
#include "10.7a.h"

using std::cout;
using std::endl;

Plorg::Plorg(const char* tag, int ci_val)
{
	int str_len = strlen(tag);
	strncpy(name, tag, MAX_CHARACTER);
	CI = ci_val;
}

void Plorg::midofy_ci(int ci_val)
{
	CI = ci_val;
}

void Plorg::report() const
{
	cout << "Name: " << name << '\t' << "CI: " << CI << endl;
}
