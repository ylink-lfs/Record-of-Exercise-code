#include <iostream>
#include <cstring>
#include "vintage_port.h"

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;
using std::strncpy;

vintage_port::vintage_port()
{
	nickname = new char[5];
	strcpy(nickname, "null");
	year = -1;
	return;
}

vintage_port::vintage_port(const char* br, int b, const char* nn, int y) : port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
	return;
}

vintage_port::vintage_port(const vintage_port& vp) : port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return;
}

vintage_port& vintage_port::operator=(const vintage_port& vp)
{
	if (&vp == this)
		return *this;
	delete[]nickname;
	port::operator=(vp);
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void vintage_port::Show() const
{
	port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
	return;
}

std::ostream& operator<<(std::ostream& os, const vintage_port& vp)
{
	return os << (port&)vp << " , " << vp.nickname << ", " << vp.year;
}