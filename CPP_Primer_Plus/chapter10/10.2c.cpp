#include <iostream>
#include <cstdlib>
#include <cstring>
#include "10.2a.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	cout << endl;
	one.FormalShow();
	two.Show();
	three.FormalShow();
	system("pause");
	return 0;
}
