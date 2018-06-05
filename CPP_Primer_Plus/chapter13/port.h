#pragma once
#include <iostream>

class port
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	port(const char* br = "none", const char* st = "none", int b = 0);
	port(const port& p);
	virtual ~port() { delete[]brand; }
	port& operator=(const port& p);
	port& operator+=(int b);  //add b to bottles
	port& operator-=(int b);  //if available, subtracts b from bottles
	int BottleCount() const { return bottles; }
	virtual void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const port& p);
};