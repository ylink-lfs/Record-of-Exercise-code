#pragma once
#include "CD.h"

class classic : public CD
{
private:
	char* artwork;
public:
	classic(const char* s1, const char* s2, int n, double x, const char* artwork_name);
	classic(const CD& cd_src, const char* artwork_name);
	classic();
	classic(const classic& src);
	classic& operator=(const classic& src);
	~classic();
	virtual void Report() const override;
};