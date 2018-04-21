//implementation
#include <iostream>
#include <string>
#include "10.3a.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Golf::Golf()
{
	string t_str;
	int t_hp;
	cout << "Enter fucking name:";
	getline(cin, t_str);
	cout << "Enter fucking handicap:";
	cin >> t_hp;
	Golf temp(t_str, t_hp);
	*this = temp;
}

Golf::Golf(const string& n_p, int val)
{
	fullname = n_p;
	handicap = val;
}

void Golf::show() const
{
	cout << "Name: " << fullname << " \tHandicap: " << handicap << endl;
}

void Golf::set_handicap(int val)
{
	handicap = val;
}