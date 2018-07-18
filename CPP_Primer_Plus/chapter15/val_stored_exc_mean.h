#pragma once
#include <iostream>
#include <exception>
#include <string>

using std::string;

class bad_hmean : public std::logic_error
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0, 
		const string& er = "Hmean error") : v1(a), v2(b), 
		logic_error(er + "\nTwo arguments: " + std::to_string(a) + ", " + std::to_string(b) + "\n") {}
};

class bad_gmean : public std::logic_error
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0, const string& er = "Gmean_error") : v1(a), v2(b),
	logic_error(er + "\nTwo arguments: " + std::to_string(a) + ", " + std::to_string(b) + "\n") {}
};