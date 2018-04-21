//driver
//玄学问题...为了编译器报LNK1120找来找去至少十几分钟，之后把函数定义的那个cpp文件exclude再include就好了，烦躁
#include <iostream>
#include <cstdlib>
#include <string>
#include "10.3a.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	Golf fuck;
	Golf shit("Bitch", 5);
	fuck.set_handicap(2);
	shit.set_handicap(6);
	fuck.show();
	system("pause");
	return 0;
}