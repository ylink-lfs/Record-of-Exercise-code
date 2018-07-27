#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
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
	fraction(const std::string& st);

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
	T shared_divisor = fra_GCD(numerator, denominator);
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
		numerator = std::abs(nm);
		denominator = std::abs(de);
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
		throw (std::invalid_argument("Denomiator should not be equal to zero\n"));
	}
	else
	{
		numerator = std::abs(p.first);
		denominator = std::abs(p.second);
		if (numerator == 0)
			denominator = 1;
		reduction();
		if (p.first * p.second < 0)
			numerator *= (-1);
		current_mode = IMPROPER;
	}
}

template <typename T>
fraction<T>::fraction(const std::string& st)
{
	int div_pos = st.find('/');
	int nm = std::stoi(st.substr(0, div_pos));
	int de = std::stoi(st.substr(div_pos + 1, st.size() - 1 - div_pos));
	if (de == 0)
	{
		throw (std::invalid_argument("Denomiator should not be equal to zero\n"));
	}
	else
	{
		numerator = std::abs(nm);
		denominator = std::abs(de);
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
	if (denominator == 1)
		cout << numerator;
	else
	{
		switch (current_mode)
		{
		case IMPROPER:
			std::cout << numerator << '/' << denominator;
			break;
		case MIXED:
			if (numerator / denominator)
				std::cout << numerator / denominator << ' ';
			std::cout << std::abs(numerator) % denominator << '/' << denominator;
			break;
		}
	}
}

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fraction<long long> sum;
	
	int tot_elem;
	cin >> tot_elem;
	while (tot_elem--)
	{
		string read_tran;
		cin >> read_tran;
		sum = sum + fraction<long long>(read_tran);
	}
	sum.switch_display_mode(fraction<long long>::MIXED);
	sum.show();
	cout << '\n';

	return 0;
}