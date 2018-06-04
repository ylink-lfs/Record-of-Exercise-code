#include <iostream>
#include <cstdlib>
#include "Header.h"

using namespace SALES;
using namespace std;

int main(void)
{
	Sales a, b;
	double ipt[3]{ 3.4, 4.5, 5.6 };
	setSales(a, ipt, 3);
	setSales(b);

	showSales(a);
	showSales(b);

	system("pause");
	return 0;
}
