#pragma once
#include <string>

class Golf
{
private:
	int handicap;
	std::string fullname;
public:
	Golf();
	Golf(const std::string& st, int val = -1);
	void show() const;
	void set_handicap(int);
};