#pragma once

class Plorg
{
private:
	static const int MAX_CHARACTER = 19;
	char name[MAX_CHARACTER];
	int CI;
public:
	Plorg(const char* tag = "plorga", int cl_val = 50);
	void midofy_ci(int ci_val);
	void report() const;
};