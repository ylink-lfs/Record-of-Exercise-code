#pragma once
#include <string>

using std::string;

class Account
{
private:
	string name;
	string account_id;
	long double savings;
public:
	Account();
	Account(const string&, const string&, long double);
	~Account() {}
	void show() const;
	bool deposit(long double);
	bool withdraw(long double);
};
