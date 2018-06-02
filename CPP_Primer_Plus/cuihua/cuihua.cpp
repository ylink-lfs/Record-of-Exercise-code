#include <cstring>
#include "cuihua.h"

using std::cin;

cuihua::cuihua()
{
	str = nullptr;
	len = 0;
	return;
}

cuihua::cuihua(const char* src)
{
	len = strlen(src);
	if (len == 0)
	{
		str = nullptr;
	}
	else
	{
		str = new char[len + 1];
		strcpy(str, src);
	}
	return;
}

cuihua::cuihua(const cuihua& src_c)
{
	len = src_c.len;
	str = new char[len + 1];
	strcpy(str, src_c.str);
	return;
}

cuihua::~cuihua()
{
	delete[]str;
	return;
}

bool cuihua::operator<(const cuihua& src) const
{
	return strcmp(str, src.str) < 0 ? true : false;
}

bool cuihua::operator>(const cuihua& src) const
{
	return !(*this < src);
}

bool cuihua::operator==(const cuihua& src) const
{
	return strcmp(str, src.str) == 0 ? true : false;
}

bool cuihua::operator!=(const cuihua& src) const
{
	return !(*this == src);
}

cuihua& cuihua::operator=(const cuihua& src)
{
	if (this == &src)
		return *this;
	delete[]str;
	len = strlen(src.str);
	str = new char[len + 1];
	strcpy(str, src.str);
	return *this;
}

cuihua& cuihua::operator=(const char* src)
{
	delete[]str;
	len = strlen(src);
	str = new char[len + 1];
	strcpy(str, src);
	return *this;
}

char& cuihua::operator[](int num)
{
	if (num < 0 || num >= len)
		return str[len - 1];
	else
		return str[num];
}

const char& cuihua::operator[](int num) const
{
	if (num < 0 || num >= len)
		return str[len - 1];
	else
		return str[num];
}

size_t cuihua::getLen() const
{
	return len;
}

istream& operator>>(istream& iss, cuihua& src)
{
	char* temp = new char[5000];
	iss.get(temp, 5000);
	if (iss)
	{
		src = temp;
	}
	while (iss && iss.get() != '\n')
		continue;
	return iss;
}

ostream& operator<<(ostream& os, const cuihua& src)
{
	return os << src.str;
}