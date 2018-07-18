#pragma once
#include <iostream>
#include <exception>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean(const char* s = "The sum of 2 arguments should not be 0.") : logic_error(s) {}
};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean(const char* s = "Both arguments should be greater than 0") : logic_error(s) {}
};