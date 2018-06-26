#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::string;

class person
{
private:
	string first_name;
	string last_name;
public:
	person() : first_name("Uninitialized"), last_name("Uninitialized") {}
	person(const string& fname, const string& lname) : first_name(fname), last_name(lname) {}
	virtual void show() const;
	void modify();
	virtual ~person() {}
};

class guns_linger : public virtual person
{
private:
	int notch;
public:
	guns_linger() : person(), notch(-1) {}
	guns_linger(const string& fname, const string& lname, const int nt = 0) : person(fname, lname), notch(nt) {}
	double draw() const;
	void show() const override;
	void show_notch() const { cout << notch; }
	void new_notch(int nt);
};

class poker_player : public virtual person
{
public:
	poker_player() : person() {}
	poker_player(const string& fname, const string& lname) : person(fname, lname) {}
	void show() const override;
	int draw() const;
};

class bad_dude : public guns_linger, public poker_player
{
public:
	bad_dude() {}
	bad_dude(const string& fname, const string& lname) : person(fname, lname), guns_linger(fname, lname),
		poker_player(fname, lname) {}
	bad_dude(const string& fname, const string& lname, const int nt) : person(fname, lname), 
		guns_linger(fname, lname, nt), poker_player(fname, lname) {}

	double gdraw() const;
	int cdraw() const;
	void show() const override;
};