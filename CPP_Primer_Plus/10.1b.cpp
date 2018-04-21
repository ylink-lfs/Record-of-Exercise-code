//implementation
#include <iostream>
#include <string>
#include <climits>
#include "10.1a.h"

Account::Account()
{
	name = "Undefined";
	account_id = "null";
	savings = DBL_MIN;
}

Account::Account(const string& n_e, const string& id, long double amount)
{
	name = n_e;
	account_id = id;
	savings = amount;
}

void Account::show() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Acount_ID: " << account_id << std::endl;
	std::cout << "Deposit: " << savings << std::endl;
	std::cout << std::endl;
}

bool Account::deposit(long double amount)
{
	if (amount < 0)
		return false;
	else
	{
		savings += amount;
		return true;
	}
}


bool Account::withdraw(long double amount)
{
	if (amount < 0 || amount > savings)
		return false;
	else
	{
		savings -= amount;
		return true;
	}
}