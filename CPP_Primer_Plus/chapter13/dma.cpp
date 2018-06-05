#include <iostream>
#include <cstring>
#include "dma.h"

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

abcDMA::abcDMA(const char* l, int r)
{
	rating = r;
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	return;
}

abcDMA::abcDMA(const abcDMA& src)
{
	rating = src.rating;
	label = new char[strlen(src.label) + 1];
	strcpy(label, src.label);
	return;
}

abcDMA& abcDMA::operator=(const abcDMA& src)
{
	if (&src == this)
		return *this;
	delete[]label;
	rating = src.rating;
	label = new char[strlen(src.label) + 1];
	strcpy(label, src.label);
	return *this;
}

abcDMA::~abcDMA()
{
	delete[]label;
}

baseDMA::baseDMA(const char* l, int r) : abcDMA(l, r)
{
}

baseDMA::baseDMA(const abcDMA& src) : abcDMA(src)
{
}

void baseDMA::View()
{
	cout << "B Class\n";
	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
	return;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r) : abcDMA(l, r)
{
	strncpy(color, c, COL_LEN);
	color[COL_LEN - 1] = '\0';
	return;
}

lacksDMA::lacksDMA(const char* c, const abcDMA& rs) : abcDMA(rs)
{
	strncpy(color, c, COL_LEN);
	color[COL_LEN - 1] = '\0';
	return;
}

lacksDMA::lacksDMA(const lacksDMA& src) : abcDMA(src)
{
	strncpy(color, src.color, COL_LEN);
	color[COL_LEN - 1] = '\0';
	return;
}

lacksDMA::lacksDMA(const abcDMA& src) : abcDMA(src)
{
	strncpy(color, "converted", COL_LEN);
	return;
}

void lacksDMA::View()
{
	cout << "L Class:\n";
	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
	cout << "Color: " << color << endl;
	return;
}

hasDMA::hasDMA(const char* s, const char* l, int r) : abcDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
	return;
}

hasDMA::hasDMA(const char* s, const abcDMA& rs) : abcDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
	return;
}

hasDMA::hasDMA(const hasDMA& hs) : abcDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
	return;
}

hasDMA::~hasDMA()
{
	delete[]style;
}

hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	if (&rs == this)
		return *this;
	delete[]style;
	abcDMA::operator=(rs);
	style = new char[strlen(rs.style) + 1];
	strcpy(style, rs.style);
	return *this;
}

void hasDMA::View()
{
	cout << "H Class:\n";
	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
	cout << "Style: " << style << endl;
	return;
}