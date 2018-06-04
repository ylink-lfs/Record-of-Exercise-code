#pragma once
#include <iostream>

using std::istream;
using std::ostream;

class cuihua
{
private:
	char* str;
	size_t len;
public:
	cuihua();
	cuihua(const char* src);
	cuihua(const cuihua& src_c);
	~cuihua();

	bool operator>(const cuihua& src) const;
	bool operator<(const cuihua& src) const;
	bool operator==(const cuihua& src) const;
	bool operator!=(const cuihua& src) const;

	cuihua& operator=(const cuihua& src);
	cuihua& operator=(const char* src);
	char& operator[](int num);
	const char& operator[](int num) const;

	size_t getLen() const;

	friend istream& operator>>(istream& iss, cuihua& src);
	friend ostream& operator<<(ostream& os, const cuihua& src);
};
