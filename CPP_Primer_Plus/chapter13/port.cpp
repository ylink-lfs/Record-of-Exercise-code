#include <iostream>
#include <cstring>
#include "port.h"

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;
using std::strncpy;

port::port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 20);
	style[19] = '\0';
	bottles = b;
	return;
}

port::port(const port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	style[19] = '\0';
	bottles = p.bottles;
	return;
}

port& port::operator=(const port& p)
{
	if (&p == this)
		return *this;
	delete[]brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	style[19] = '\0';
	bottles = p.bottles;
	return *this;
}

port& port::operator+=(int b)
{
	bottles += b;
	return *this;
}

port& port::operator-=(int b)
{
	if (bottles >= b)
		bottles -= b;
	else
		cout << "Current bottle count is fewer than given amount. Ignore this operation.\n";
	return *this;
}

void port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
	return;
}

std::ostream& operator<<(std::ostream& os, const port& p)
{
	return os << p.brand << ", " << p.style << ", " << p.bottles;
}