#include <iostream>
#include <vector>
#include <cstdlib>
#include "poker_person.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

int main(void)
{
	vector<person*> polyvec;
	for (int i = 0; i < 5; i++)
	{
		int switcher = 0;
		cout << "Enter the person you want to add info. GunsLinger: 0, PokerPlayer: 1, BadDude: 2\n";
		cout << "Waiting for input: ";
		while (cin >> switcher && (switcher < 0 || switcher > 2))
		{
			cout << "Unknown specifier. Please enter 0-2: ";
		}
		cout << "Enter the person's first name and last name: ";
		string fn, ln;
		cin >> fn >> ln;
		int notches = 0;
		if (switcher != 1)
		{
			cout << "Please enter notch number: ";
			cin >> notches;
		}
		switch (switcher)
		{
		case 0:
			polyvec.push_back(new guns_linger(fn, ln, notches));
			break;
		case 1:
			polyvec.push_back(new poker_player(fn, ln));
			break;
		case 2:
			polyvec.push_back(new bad_dude(fn, ln, notches));
			break;
		}
	}
	for (auto it = polyvec.begin(); it < polyvec.end(); it++)
	{
		(*it)->show();
		delete (*it);
	}

	system("pause");
	return 0;
}

/*
Sample input:
0
Prior Shooter
4
2
Prior Dude
5
1
Prior Poker
0
Senior Shooter
10
2
Senior Dude
2
*/