#pragma once
#include <iostream>

class abcDMA
{
protected:
	char* label;
	int rating;
public:
	abcDMA(const char* l = "null", int r = 0);
	abcDMA& operator=(const abcDMA& src);
	abcDMA(const abcDMA& src);
	virtual ~abcDMA();
	virtual void View() = 0;
};

class baseDMA : public abcDMA
{
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const abcDMA& src);
	void View();
};

class lacksDMA : public abcDMA
{
private:
	enum { COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "black", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const abcDMA& rs);
	lacksDMA(const lacksDMA& src);
	lacksDMA(const abcDMA& src);
	void View();
};

class hasDMA : public abcDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const abcDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	void View();
};

