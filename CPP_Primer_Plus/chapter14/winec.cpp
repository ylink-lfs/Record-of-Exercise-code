#include <iostream>
#include "winec.h"

using std::cin;
using std::cout;
using std::endl;

wine::wine()
{
}

wine::wine(const char* l, int y, const int yr[], const int bot[]) : string(l), pair(intarr(yr, y), intarr(bot, y))
{	
}

wine::wine(const char* l, int y) : string(l), pair(intarr(y), intarr(y))
{
}

void wine::get_bottles()
{
	cout << "Enter Gully Wash data for " << pair_intarr(*this).first.size() << " year(s):\n";
	for (int i = 0; i < pair_intarr(*this).first.size(); i++)
	{
		cout << "Enter year: ";
		cin >> pair<valarray<int>, valarray<int>>::first.operator[](i);
		cout << "Enter bottles for that year: ";
		cin >> pair<valarray<int>, valarray<int>>::second.operator[](i);
	}
}

void wine::show() const
{
	cout << "Wine: " << (const string&)(*this) << endl;
	cout.width(11);
	cout << "Year";
	cout.width(11);
	cout << "Bottles" << endl;
	for (int i = 0; i < pair_intarr(*this).first.size(); i++)
	{
		cout.width(11);
		cout << pair_intarr(*this).first[i];
		cout.width(6);
		cout << pair_intarr(*this).second[i] << endl;
	}
	cout.width(0);
}

const string& wine::label() const
{
	return (const string&)(*this);
}

int wine::sum() const
{
	return pair_intarr(*this).second.sum();
}
