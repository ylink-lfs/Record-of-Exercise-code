#pragma once
#include <deque>
#include <string>
#include <iostream>

using std::string;

class big_integer
{
private:
	std::deque<int> digits;
	bool symbol_flag;

	void calculate_carry();
	void calculate_borrow();
	void wipe_prefix_zero();
	string wash_src_string(const string& s) const;
	string conversion_to_str() const;
public:
	//C++11 Initializer List
	big_integer() : digits({0}), symbol_flag(false) {}
	big_integer(const string& s);
	big_integer(const long long n);
	big_integer(std::deque<int>::const_iterator bg, std::deque<int>::const_iterator ed) : digits(bg, ed) {}

	big_integer operator+(const big_integer& bint) const;
	big_integer operator-(const big_integer& bint) const;
	big_integer operator*(const big_integer& bint) const;
	big_integer operator/(const big_integer& bint) const;
	big_integer operator%(const big_integer& bint) const;

	//Minus operator
	big_integer operator-() const;
	//Prefix ++
	big_integer operator++();
	//Postfix ++
	big_integer operator++(int);
	big_integer operator--();
	big_integer operator--(int);

	big_integer operator+=(const big_integer& bint);
	big_integer operator-=(const big_integer& bint);
	big_integer operator*=(const big_integer& bint);
	big_integer operator/=(const big_integer& bint);
	big_integer operator%=(const big_integer& bint);

	bool operator<(const big_integer& bint) const;
	bool operator>(const big_integer& bint) const;
	bool operator<=(const big_integer& bint) const;
	bool operator>=(const big_integer& bint) const;
	bool operator==(const big_integer& bint) const;
	bool operator!=(const big_integer& bint) const;

	big_integer abs() const;
	bool is_palindrome() const;

	friend std::istream& operator>>(std::istream& ist, big_integer& bint);
	friend std::ostream& operator<<(std::ostream& os, const big_integer& bint);
};