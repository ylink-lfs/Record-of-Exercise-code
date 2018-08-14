#include <algorithm>
#include <vector>
#include "big_integer.h"

using std::vector;

//Private Methods
void big_integer::calculate_carry()
{
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] >= 10)
		{
			int carry_num = digits[i] / 10;
			digits[i] %= 10;
			if (i == 0)
			{
				digits.push_front(carry_num);
			}
			else
			{
				digits[i - 1] += carry_num;
			}
		}
	}
}

void big_integer::calculate_borrow()
{
	for (int i = digits.size() - 1; i > 0; i--)
	{
		if (digits[i] < 0)
		{
			digits[i] += 10;
			digits[i - 1] -= 1;
		}
	}
}

void big_integer::wipe_prefix_zero()
{
	while (!digits.empty() && digits[0] == 0)
		digits.pop_front();
	if (digits.empty())
	{
		digits.push_back(0);
		symbol_flag = false;
	}
}

string big_integer::wash_src_string(const string & s) const
{
	string edit_str(s);

	//Cut off decimal part
	string::size_type dot_pos = edit_str.find('.', 0);
	if (dot_pos != string::npos)
	{
		edit_str.erase(edit_str.begin() + dot_pos, edit_str.end());
	}

	//Wipe prefix 0
	string::size_type prefix_zero_begin = 0;
	if (edit_str[0] == '-')
		prefix_zero_begin++;
	string::size_type prefix_zero_length = 0;
	while (edit_str[prefix_zero_begin + prefix_zero_length] == 0)
		prefix_zero_length++;
	edit_str.erase(prefix_zero_begin, prefix_zero_length);

	//Prevent "-0" comes out
	if (edit_str.size() == 1 && edit_str[0] == '-')
		edit_str.clear();
	//If all characters are wiped out, then add one '0' to it
	if (edit_str.empty())
		edit_str.push_back('0');
	return edit_str;
}

string big_integer::conversion_to_str() const
{
	string tmp;
	for (int i = 0; i < digits.size(); i++)
	{
		tmp += static_cast<char>(digits[i] + '0');
	}
	return tmp;
}

//Public Methods
big_integer::big_integer(const string & s)
{
	string src(wash_src_string(s));
	auto begin_it = src.begin();
	symbol_flag = false;
	if (src[0] == '-')
	{
		symbol_flag = true;
		begin_it++;
	}

	for (auto it = begin_it; it < src.end(); it++)
	{
		digits.push_back(*it - '0');
	}
}

big_integer::big_integer(const long long n)
{
	long long num = n;
	while (num)
	{
		int fraction = num % 10;
		digits.push_front(fraction);
		num /= 10;
	}
}

big_integer big_integer::operator+(const big_integer & bint) const
{
	big_integer result;
	const big_integer& shorter = (digits.size() < bint.digits.size()) ? (*this) : bint;
	const big_integer& longer = (digits.size() <= bint.digits.size()) ? bint : (*this);
	for (int i = longer.digits.size() - 1; i >= 0; i--)
	{

	}
}

big_integer big_integer::operator-(const big_integer & bint) const
{
	return big_integer();
}

big_integer big_integer::operator*(const big_integer & bint) const
{
	return big_integer();
}

big_integer big_integer::operator/(const big_integer & bint) const
{
	big_integer low(1);
	big_integer high(bint);
	while (low < high)
	{
		
	}
	return low;
}

big_integer big_integer::operator%(const big_integer & bint) const
{
	return big_integer();
}

big_integer big_integer::operator-() const
{
	big_integer res(*this);
	res.symbol_flag ^= false;
	return res;
}

//Prefix
big_integer big_integer::operator++()
{
	(*this) += 1;
	return *this;
}

//Postfix
big_integer big_integer::operator++(int)
{
	big_integer tmp = *this;
	(*this) += 1;
	return tmp;
}

big_integer big_integer::operator--()
{
	(*this) -= 1;
	return *this;
}

big_integer big_integer::operator--(int)
{
	big_integer tmp = *this;
	(*this) -= 1;
	return tmp;
}

big_integer big_integer::operator+=(const big_integer & bint)
{
	(*this) = (*this) + bint;
	return *this;
}

big_integer big_integer::operator-=(const big_integer & bint)
{
	(*this) = (*this) - bint;
	return *this;
}

big_integer big_integer::operator*=(const big_integer & bint)
{
	(*this) = (*this) * bint;
	return *this;
}

big_integer big_integer::operator/=(const big_integer & bint)
{
	(*this) = (*this) / bint;
	return *this;
}

big_integer big_integer::operator%=(const big_integer & bint)
{
	(*this) = (*this) % bint;
	return *this;
}

bool big_integer::operator<(const big_integer & bint) const
{
	//Different symbol
	if (symbol_flag != bint.symbol_flag)
	{
		return symbol_flag;
	}

	//Use their abs form to compare

	bool res;
	//If number length are not same, then the longer one is bigger
	if (digits.size() != bint.digits.size())
		res = digits.size() < bint.digits.size();
	//Compare from top digit to below one
	else
	{
		int i;
		for (i = 0; i < digits.size(); i++)
		{
			if (digits[i] != bint.digits[i])
			{
				res = digits[i] < bint.digits[i];
				break;
			}
		}
		if (i == digits.size())
			res = digits[0] < bint.digits[0];
	}

	//Adjust minus result
	if (symbol_flag)
	{
		res ^= false;
	}
	return res;
}

bool big_integer::operator>(const big_integer & bint) const
{
	return ((*this) != bint) && !((*this) < bint);
}

bool big_integer::operator<=(const big_integer & bint) const
{
	return ((*this) < bint) || ((*this) == bint);
}

bool big_integer::operator>=(const big_integer & bint) const
{
	return ((*this) > bint) || ((*this) == bint);
}

bool big_integer::operator==(const big_integer & bint) const
{
	return (symbol_flag == bint.symbol_flag) && (digits == bint.digits);
}

bool big_integer::operator!=(const big_integer & bint) const
{
	return !((*this) == bint);
}

std::istream & operator>>(std::istream & ist, big_integer & bint)
{
	string tmp;
	ist >> tmp;
	bint = big_integer(tmp);
	return ist;
}

std::ostream & operator<<(std::ostream & os, const big_integer & bint)
{
	if (bint.symbol_flag)
		os << '-';
	for (size_t i = 0; i < bint.digits.size(); i++)
	{
		os << bint.digits[i];
	}
	return os;
}

big_integer big_integer::abs() const
{
	big_integer res(*this);
	res.symbol_flag = false;
	return res;
}

bool big_integer::is_palindrome() const
{
	string jdg(conversion_to_str());
	for (size_t i = 0; i <= jdg.size() / 2; i++)
	{
		size_t mirror_index = jdg.size() - i - 1;
		if (jdg[i] != jdg[mirror_index])
			return false;
	}
	return true;
}