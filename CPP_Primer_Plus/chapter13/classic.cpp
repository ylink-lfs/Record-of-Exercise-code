#include <iostream>
#include <cstring>
#include "classic.h"

using std::cout;
using std::endl;
using std::strcpy;
using std::strlen;

classic::classic(const char* s1, const char* s2, int n, double x,
	const char* artwork_name) : CD(s1, s2, n, x)
{
	artwork = new char[strlen(artwork_name) + 1];
	strcpy(artwork, artwork_name);
	return;
}

classic::classic(const CD& cd_src, const char* artwork_name) : CD(cd_src)
{
	artwork = new char[strlen(artwork_name) + 1];
	strcpy(artwork, artwork_name);
	return;
}

//Implicitly called CD()
classic::classic()
{
	artwork = nullptr;
	return;
}

classic::classic(const classic& src) : CD(src)
{
	artwork = new char[strlen(src.artwork) + 1];
	strcpy(artwork, src.artwork);
	return;
}

classic& classic::operator=(const classic& src)
{
	if (this == &src)
		return *this;
	delete[]artwork;
	CD::operator=(src);
	artwork = new char[strlen(src.artwork) + 1];
	strcpy(artwork, src.artwork);
	return *this;
}

classic::~classic()
{
	delete[]artwork;
}

void classic::Report() const
{
	CD::Report();
	cout << "***Artwork: " << artwork << "***\n";
	return;
}