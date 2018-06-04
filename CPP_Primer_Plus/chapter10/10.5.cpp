#include <iostream>
#include <cstdlib>
#include <cstring>
#include "stack.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	const int CUS_NUM = 8;
	customer slut[CUS_NUM];
	customer cache;
	double tot = 0;
	Stack t_s;
	for (int i = 0; i < CUS_NUM; i++)
	{
		cout << "Name: ";
		scanf("%s", slut[i].fullname);
		cout << "Payment: ";
		scanf("%lf", &(slut[i].payment));
		t_s.push(slut[i]);
	}
	for (int i = 0; i < CUS_NUM; i++)
	{
		t_s.pop(cache);
		tot += cache.payment;
		cout << tot << ' ';
	}
	system("pause");
	return 0;
}
