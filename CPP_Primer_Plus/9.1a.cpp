#include <iostream>
#include <cstdlib>
#include <cstring>
#include "golf.h"

void setgolf(golf& g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	std::cout << "Enter fucking name:";
	std::cin.get(g.fullname, Len);
	std::cin.get();
	if (g.fullname[0] == '\0' || g.fullname[0] == '\n')
	{
		fprintf(stderr, "Heap Corrupted\n");
		return 0;
	}
	std::cout << "Enter fucking handicap:";
	std::cin >> g.handicap;
	std::cin.get();
	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "Name: " << g.fullname << " \tHandicap: " << g.handicap << std::endl;
	return;
}