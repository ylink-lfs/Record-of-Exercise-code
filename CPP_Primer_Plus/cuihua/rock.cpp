#include <iostream>
#include <cstdlib>
#include "cuihua.h"

const int ArSize = 10;
const int MaxLen = 81;

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cuihua name;
	cout << "Hi, what's your name?\n";
	cin >> name;

	cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
	cuihua sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
		{
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		}
		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].getLen() < sayings[shortest].getLen())
			{
				shortest = i;
			}
			if (sayings[i] < sayings[first])
			{
				first = i;
			}
		}
		cout << "Shortest saying:\n" << sayings[shortest] << endl;
		cout << "First alphabetically:\n" << sayings[first] << endl;
	}
	else
	{
		cout << "No input! Bye\n";
	}
	system("pause");
	return 0;
}

/*
test case:
Misty Gutz

a fool and his money aresoon parted
penny wise, pound foolish
the love of money is the root of much evil
out of sight, out of mind
absence makes the heart grow fonder
absinthe makes the hart grow fonder
*/
