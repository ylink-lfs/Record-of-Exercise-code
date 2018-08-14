//Brute big integer class implementation. No digit press, no calculation process optimization.
#pragma once
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::istream;
using std::ostream;

class big_integer
{
private:
	vector<int> digits;
	bool symbol_flag;
	void calculate_carry();
	void calculate_borrow();
	string wash_input_str(const string& s) const;
	void wipe_prefix_zero();
public:
	big_integer() : digits({0}), symbol_flag(false) {}
	big_integer(vector<int>::const_iterator bg, vector<int>::const_iterator ed) 
		: digits(bg, ed), symbol_flag(false) {}

	big_integer(const string& num_str);
	big_integer(const long long num);
	
	bool judge_palindrome() const;	
	vector<int> digit_distribution() const;
	void reverse();
	big_integer abs() const
	{
		big_integer res(*this); res.symbol_flag = false; return res;
	}

	big_integer operator-() const 
	{ 
		big_integer res(*this); res.symbol_flag ^= false; return res; 
	}

	big_integer operator+(const big_integer& bint) const;
	big_integer operator-(const big_integer& bint) const;
	big_integer operator*(const big_integer& bint) const;
	big_integer operator/(const big_integer& bint) const;
	big_integer operator%(const big_integer& bint) const;

	bool operator<(const big_integer& bint) const;
	bool operator>(const big_integer& bint) const;
	bool operator<=(const big_integer& bint) const;
	bool operator>=(const big_integer& bint) const;
	bool operator==(const big_integer& bint) const;
	bool operator!=(const big_integer& bint) const;

	big_integer operator+=(const big_integer& bint);

	friend istream& operator>>(istream& ist, big_integer& bint);
	friend ostream& operator<<(ostream& os, const big_integer& bint);
	friend void swap(big_integer& bint1, big_integer& bint2) 
	{ 
		std::swap(bint1.digits, bint2.digits); std::swap(bint1.symbol_flag, bint2.symbol_flag); 
	}
};
