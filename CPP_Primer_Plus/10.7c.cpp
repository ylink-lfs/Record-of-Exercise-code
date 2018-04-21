#include <iostream>
#include <cstdlib>
#include "10.7a.h"

using std::cout;
using std::endl;

int main(void)
{
	Plorg a;
	Plorg b("Love you", 3);
	a.midofy_ci(2);
	a.report();
	b.report();
	system("pause");
	return 0;
}