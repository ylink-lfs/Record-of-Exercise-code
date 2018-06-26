#pragma once
#include <utility>
#include <valarray>
#include <string>

using std::string;
using std::valarray;
using std::pair;

using intarr = valarray<int>;
using pair_intarr = pair<intarr, intarr>;

class wine : private string, private pair_intarr
{
public:
	wine();
	wine(const char* l, int y, const int yr[], const int bot[]);
	wine(const char* l, int y);
	
	void get_bottles();
	void show() const;
	const string& label() const;
	int sum() const;
};