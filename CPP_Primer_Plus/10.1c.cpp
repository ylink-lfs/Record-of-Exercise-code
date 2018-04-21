//driver
#include <iostream>
#include <cstdlib>
#include <string>
#include "10.1a.h"

using std::cout;
using std::string;
using std::endl;

int main(void)
{
	Account customer_info[10];
	string base = "Twin bro";
	string cache;
	bool check;
	for (int i = 0; i < 10; i++)
	{
		cache = i + 48;
		customer_info[i] = Account(base + cache, cache, i + 80000);
	}
	check = customer_info[2].deposit(80006.0);
	for (auto i : customer_info)
		i.show();
	system("pause");
	return 0;
}