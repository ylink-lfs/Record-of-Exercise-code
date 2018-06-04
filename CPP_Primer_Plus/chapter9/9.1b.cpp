#include <iostream>
#include <cstdlib>
#include "golf.h"

using namespace std;

int main(void)
{
	golf fuck[100];
	int i;
	for (i = 0; i < 10; i++)
	{
		setgolf(fuck[i]);
	}
	for (i = 0; i < 10; i++)
	{
		showgolf(fuck[i]);
	}
	setgolf(fuck[1], "bitch user", 99);
	handicap(fuck[0], 8888);
	for (i = 0; i < 10; i++)
	{
		showgolf(fuck[i]);
	}
	system("pause");
	return 0;
}
