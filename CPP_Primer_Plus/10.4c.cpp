#include <iostream>
#include <cstdlib>
#include "10.4a.h"

using namespace SALES;
using namespace std;

int main(void)
{
	double ipt[3]{ 3.4, 4.5, 5.6 };
	Sales a(ipt, 3);
	double legel[4]{ 7.0, 9.5, 10.9, 11.6 };
	Sales b(legel, 4);
	Sales c;
	a.show();
	b.show();
	c.show();
	system("pause");
	return 0;
}