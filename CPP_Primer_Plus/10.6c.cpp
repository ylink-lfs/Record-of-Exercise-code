#include <iostream>
#include <cstdlib>
#include "10.6a.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	Move cor1(3.0, 4.9);
	Move cor2(1.0, 1.0);
	Move cor3 = cor1.merge(cor2);
	cor3.show_coor();
	cor1.reset();
	cor1.show_coor();
	system("pause");
	return 0;
}