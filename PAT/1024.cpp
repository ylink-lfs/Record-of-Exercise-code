#pragma once
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::string;
using std::istream;
using std::ostream;

//Use an integer type to initialize the class
template <typename T>
class biguint
{
private:
	vector<T> digit;
	void calculate_carry();
	void calculate_borrow();
	string wash_input(const string& st) const;
public:
	biguint() { digit.push_back(0); }
	biguint(const string& st);
	biguint(const long long num);


	biguint<T> operator+(const biguint<T>& bint) const;
	biguint<T> operator-(const biguint<T>& bint) const;
	biguint<T> operator*(const biguint<T>& bint) const;
	biguint<T> operator/(const biguint<T>& bint) const;
	biguint<T> operator%(const biguint<T>& bint) const;

	bool operator<(const biguint<T>& bint) const;
	bool operator>(const biguint<T>& bint) const;
	bool operator==(const biguint<T>& bint) const;
	bool operator!=(const biguint<T>& bint) const;
	bool operator<=(const biguint<T>& bint) const;
	bool operator>=(const biguint<T>& bint) const;

	biguint<T> operator+=(const biguint<T>& bint);
	biguint<T> operator-=(const biguint<T>& bint);
	biguint<T> operator*=(const biguint<T>& bint);
	biguint<T> operator/=(const biguint<T>& bint);
	biguint<T> operator%=(const biguint<T>& bint);

	bool judge_palindrome() const;
	void digit_distribution(vector<pair<int, int>>& v);
	void reverse_digit() { std::reverse(digit.begin(), digit.end()); }

	friend istream& operator>>(istream& ist, biguint<T>& bint)
	{
		string tmp;
		ist >> tmp;
		bint = tmp;
		return ist;
	}
	friend ostream& operator<<(ostream& os, const biguint<T>& bint)
	{
		for (int i = bint.digit.size() - 1; i >= 0; i--)
		{
			os << bint.digit[i];
		}
		return os;
	}
};

//Public Methods
template <typename T>
biguint<T>::biguint(const string& st)
{
	string actual_ipt(wash_input(st));
	digit.resize(actual_ipt.size());

	//Reversal assignment
	for (int i = 0; i < digit.size(); i++)
	{
		digit[i] = actual_ipt[actual_ipt.size() - i - 1] - '0';
	}
}

template <typename T>
biguint<T>::biguint(const long long num) : biguint(std::to_string(num))
{
	//Delegating Constructor (C++11 feature)
}


template<typename T>
biguint<T> biguint<T>::operator+(const biguint<T>& bint) const
{
	const biguint<T>& shorter = (digit.size() > bint.digit.size()) ? bint : (*this);
	const biguint<T>& longer = (digit.size() <= bint.digit.size()) ? bint : (*this);
	biguint<T> result(longer);
	for (int i = 0; i < shorter.digit.size(); i++)
	{
		result.digit[i] += shorter.digit[i];
	}
	result.calculate_carry();
	return result;
}

//Guarantee that first opt num is bigger than second num
template <typename T>
biguint<T> biguint<T>::operator-(const biguint<T>& bint) const
{
	biguint<T> result(*this);
	for (int i = 0; i < bint.digit.size(); i++)
	{
		result.digit[i] -= bint.digit[i];
	}
	result.calculate_borrow();
	return result;
}

template<typename T>
biguint<T> biguint<T>::operator*(const biguint<T>& bint) const
{
	biguint<T> result;
	const biguint<T>& shorter = digit.size() > bint.digit.size() ? bint : (*this);
	const biguint<T>& longer = digit.size() <= bint.digit.size() ? bint : (*this);
	for (int i = 0; i < shorter.digit.size(); i++)
	{
		biguint<T> tmp;
		tmp.digit.clear();
		for (int j = 0; j < i; j++)
		{
			tmp.digit.push_back(0);
		}
		for (int j = 0; j < longer.digit.size(); j++)
		{
			tmp.digit.push_back(shorter.digit[i] * longer.digit[j]);
		}
		tmp.calculate_carry();
		result += tmp;
	}
	while (result.digit.size() && result.digit[result.digit.size() - 1] == 0)
		result.digit.pop_back();
	if (result.digit.size() == 0)
		result.digit.push_back(0);
	return result;
}

template<typename T>
biguint<T> biguint<T>::operator/(const biguint<T>& bint) const
{
	biguint<T> result;
	result.digit.clear();
	biguint<T> wait_for_division(digit[digit.size() - 1]);
	for (int i = digit.size() - 1; i >= 0; i--)
	{
		int division_val = 0;
		biguint<T> tmp = bint * division_val;
		while (bint * division_val <= wait_for_division)
			division_val++;
		division_val--;
		result.digit.insert(result.digit.begin(), division_val);
		if (i != 0)
		{
			if (division_val == 0)
			{
				wait_for_division = wait_for_division * 10 + digit[i - 1];
			}
			else
			{
				wait_for_division = (wait_for_division - bint * division_val) * 10 + digit[i - 1];
			}
		}
	}
	while (result.digit.size() && result.digit[result.digit.size() - 1] == 0)
		result.digit.pop_back();
	if (result.digit.size() == 0)
		result.digit.push_back(0);
	return result;
}

template<typename T>
biguint<T> biguint<T>::operator%(const biguint<T>& bint) const
{
	biguint<T> result((*this) - (*this / bint) * bint);
	while (result.digit.size() && result.digit[result.digit.size() - 1] == 0)
		result.digit.pop_back();
	if (result.digit.size() == 0)
		result.digit.push_back(0);
	return result;
}

template<typename T>
bool biguint<T>::operator<(const biguint<T>& bint) const
{
	if (digit.size() != bint.digit.size())
	{
		return digit.size() < bint.digit.size();
	}
	for (int i = digit.size() - 1; i > 0; i--)
	{
		if (digit[i] != bint.digit[i])
			return digit[i] < bint.digit[i];
	}
	return digit[0] < bint.digit[0];
}

template<typename T>
bool biguint<T>::operator>(const biguint<T>& bint) const
{
	return (*this != bint) && !(*this < bint);
}

template<typename T>
bool biguint<T>::operator==(const biguint<T>& bint) const
{
	return digit == bint.digit;
}

template<typename T>
bool biguint<T>::operator!=(const biguint<T>& bint) const
{
	return !(*this == bint);
}

template<typename T>
bool biguint<T>::operator<=(const biguint<T>& bint) const
{
	return (*this < bint) || (*this == bint);
}

template<typename T>
bool biguint<T>::operator>=(const biguint<T>& bint) const
{
	return (*this > bint) || (*this == bint);
}

template<typename T>
biguint<T> biguint<T>::operator+=(const biguint<T>& bint)
{
	*this = (*this) + bint;
	return *this;
}

template<typename T>
biguint<T> biguint<T>::operator-=(const biguint<T>& bint)
{
	*this = (*this) - bint;
	return *this;
}

template<typename T>
biguint<T> biguint<T>::operator*=(const biguint<T>& bint)
{
	*this = (*this) * bint;
	return *this;
}

template<typename T>
biguint<T> biguint<T>::operator/=(const biguint<T>& bint)
{
	*this = (*this) / bint;
	return *this;
}

template<typename T>
biguint<T> biguint<T>::operator%=(const biguint<T>& bint)
{
	*this = (*this) % bint;
	return *this;
}

template<typename T>
bool biguint<T>::judge_palindrome() const
{
	auto it1 = digit.begin();
	auto it2 = digit.end() - 1;
	while (it1 < it2)
	{
		if (*it1 != *it2)
			return false;
		it1++;
		it2--;
	}
	return true;
}

template <typename T>
void biguint<T>::digit_distribution(vector<pair<int, int>>& v)
{
	v.clear();
	for (int i = 0; i < 10; i++)
	{
		v.push_back(std::make_pair(i, 0));
	}
	for (int i = 0; i < digit.size(); i++)
	{
		v[static_cast<int>(digit[i])].second++;
	}
}

//Private Methods
template <typename T>
void biguint<T>::calculate_carry()
{
	for (int i = 0; i < digit.size(); i++)
	{
		if (digit[i] >= 10)
		{
			int carry = digit[i] / 10;
			digit[i] %= 10;
			if (i == digit.size() - 1)
			{
				digit.push_back(carry);
			}
			else
			{
				digit[i + 1] += carry;
			}
		}
	}
}

template <typename T>
void biguint<T>::calculate_borrow()
{
	for (int i = 0; i < digit.size() - 1; i++)
	{
		if (digit[i] < 0)
		{
			digit[i] += 10;
			digit[i + 1] -= 1;
		}
	}
}

template <typename T>
string biguint<T>::wash_input(const string& st) const
{
	string edit_st(st);
	//Cut off decimal part
	int dot_pos;
	if ((dot_pos = edit_st.find('.', 0)) != string::npos)
	{
		edit_st.erase(edit_st.begin() + dot_pos, edit_st.end());
	}

	//Wipe prefix '0'
	int wipe_prefix_begin = 0;
	int wipe_prefix_len = 0;
	for (; edit_st[wipe_prefix_begin + wipe_prefix_len] == '0'; wipe_prefix_len++)
		;
	edit_st.erase(wipe_prefix_begin, wipe_prefix_len);

	//If the digits are all wiped out, then add one '0' to the string
	if (edit_st.size() == 0)
		edit_st.push_back('0');
	return edit_st;
}

int main(void)
{
	biguint<int> initial_num;	
	int max_step;
	std::cin >> initial_num >> max_step;
	biguint<int> cur(initial_num);
	biguint<int> tmp;
	int cur_step = 0;

	if (initial_num.judge_palindrome())
	{
		std::cout << initial_num << '\n' << cur_step << '\n';
		system("pause");
		return 0;
	}
	while (cur_step < max_step)
	{
		tmp = cur;
		cur.reverse_digit();
		tmp += cur;
		cur_step++;
		if (tmp.judge_palindrome())
			break;
		cur = tmp;
	}
	std::cout << tmp << '\n' << cur_step << '\n';
	system("pause");
	return 0;
}