#include <iostream>
#include <cstring>
#include "CD.h"

using std::cout;
using std::endl;
using std::strcpy;
using std::strlen;

CD::CD(const char* s1, const char* s2, int n, double x)
{
	selections = n;
	playtime = x;
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	return;
}

CD::CD()
{
	performers = label = nullptr;
	selections = 0;
	playtime = 0.0;
	return;
}

CD::~CD()
{
	delete[]performers;
	delete[]label;
	return;
}

CD::CD(const CD& d)
{
	delete[]performers;
	delete[]label;
	selections = d.selections;
	playtime = d.playtime;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	return;
}

//CD is base class, so there's no need to explicitly call operator=()
CD& CD::operator=(const CD& d)
{
	if (this == &d)
		return *this;
	delete[]performers;
	delete[]label;
	selections = d.selections;
	playtime = d.playtime;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	return *this;
}

void CD::Report() const
{
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << playtime << endl;
	return;
}