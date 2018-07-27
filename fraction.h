#pragma once
#include <algorithm>
#include <exception>
#include <iostream>
#include <utility>

//If use non-integer type to initialize the class, then result is undefined
template <typename T>
class fraction
{
public:
	enum display_mode { IMPROPER, MIXED };
private:
	//numerator is the upper part of a fraction
	//numerator stores the positivity of the fraction
	T numerator;
	T denominator;
	T fra_GCD(const T a, const T b) const;
	T fra_LCM(const T a, const T b) const;
	void reduction();
	display_mode current_mode;
public:
	fraction() : numerator(0), denominator(1) {}
	fraction(const T nm, const T de);
	fraction(const std::pair<T, T>& p);

	fraction<T> operator-() const;
	fraction<T> operator+(const fraction<T>& fc) const;
	fraction<T> operator-(const fraction<T>& fc) const;
	fraction<T> operator*(const fraction<T>& fc) const;
	fraction<T> operator/(const fraction<T>& fc) const;

	T numerator_val() const { return numerator; }
	T denominator_val() const { return denominator; }
	void switch_display_mode(display_mode dm = MIXED) { current_mode = dm; }

	void show() const;

	friend std::ostream& operator<<(std::ostream& os, const fraction<T>& fc)
	{
		if (fc.denominator == 1)
			os << fc.numerator;
		else
			os << fc.numerator << '/' << fc.denominator;
		return os;
	}
};

template <typename T>
T fraction<T>::fra_GCD(const T a, const T b) const
{
	return b == 0 ? a : fra_GCD(b, a % b);
}

template <typename T>
T fraction<T>::fra_LCM(const T a, const T b) const
{
	return a / fra_GCD(a, b) * b;
}

template <typename T>
void fraction<T>::reduction()
{
	int shared_divisor = fra_GCD(numerator, denominator);
	numerator /= shared_divisor;
	denominator /= shared_divisor;
}

template <typename T>
fraction<T>::fraction(const T nm, const T de)
{
	if (de == 0)
	{
		throw (std::invalid_argument("Denomiator should not be equal to zero\n"));		
	}
	else
	{
		numerator = abs(nm);
		denominator = abs(de);
		if (numerator == 0)
			denominator = 1;		
		reduction();
		if (nm * de < 0)
			numerator *= (-1);
		current_mode = IMPROPER;
	}
}

template <typename T>
fraction<T>::fraction(const std::pair<T, T>& p)
{
	if (p.second == 0)
	{
		throw (std::invalid_argument());
	}
	else
	{
		numerator = abs(p.first);
		denominator = abs(p.second);
		if (numerator == 0)
			denominator = 1;		
		reduction();
		if (nm * de < 0)
			numerator *= (-1);
		current_mode = IMPROPER;
	}
}

template <typename T>
fraction<T> fraction<T>::operator-() const
{
	return fraction(-numerator, denominator);
}

template <typename T>
fraction<T> fraction<T>::operator+(const fraction<T>& fc) const
{
	return fraction(numerator * fc.denominator + fc.numerator * denominator, denominator * fc.denominator);
}

template <typename T>
fraction<T> fraction<T>::operator-(const fraction<T>& fc) const
{
	return (*this) + (-fc);
}

template <typename T>
fraction<T> fraction<T>::operator*(const fraction<T>& fc) const
{
	return fraction(numerator * fc.numerator, denominator * fc.denominator);
}

template <typename T>
fraction<T> fraction<T>::operator/(const fraction<T>& fc) const
{
	return *this * fraction(fc.denominator, fc.numerator);
}

template <typename T>
void fraction<T>::show() const
{
	switch (current_mode)
	{
	case IMPROPER:
		cout << numerator << '/' << denominator;
		break;
	case MIXED:
		cout << numerator / denominator << ' ' << abs(numerator) % denominator << '/' << denominator;
		break;
	}
}