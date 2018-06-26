#include <iostream>
#include <cstdlib>
#include <ctime>
#include "poker_person.h"

using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;


//No line break added
void person::show() const
{
	cout << first_name << ' ' << last_name;
}

void person::modify()
{
	cout << "Plz enter the new person's full name: ";
	cin >> first_name >> last_name;
}

double guns_linger::draw() const
{
	srand(time(nullptr));
	double ten_place = rand() % 10;
	double unit_place = rand() % 10;
	double decile = rand() % 10;
	double centile = rand() % 10;
	return ten_place * 10 + unit_place + decile / 10 + centile / 100;
}

//Line break added
void guns_linger::show() const
{
	cout << "GunsLinger's name: ";
	person::show();
	cout << endl;
	cout << "Gun's notche(s): " << notch << endl;
}

void guns_linger::new_notch(int nt)
{
	notch = nt;
}

//Line break added
void poker_player::show() const
{
	cout << "PokerPlayer's name: ";
	person::show();
	cout << endl;
}

int poker_player::draw() const
{
	srand(time(nullptr));
	return rand() % 52 + 1;
}

double bad_dude::gdraw() const
{
	return guns_linger::draw();
}

int bad_dude::cdraw() const
{
	return poker_player::draw();
}

void bad_dude::show() const
{
	cout << "BadDude's name: ";
	person::show();
	cout << endl;
	cout << "Notch number: ";
	show_notch();
	cout << endl;
}