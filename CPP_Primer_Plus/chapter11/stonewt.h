#pragma once
#include <iostream>
class Stonewt
{
private:
	enum {Lbs_per_stn = 14};
	enum STATUS{STONE, POUNDS_FLT, POUNDS_INT};
	STATUS cur_status;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);  //total weight = lbs(pounds)
	Stonewt(int stn, double lbs);  //total weight = stn(stones) + lbs(pounds)
	Stonewt();
	~Stonewt();
	void switch_to_STONE();
	void switch_to_POU_FLT();
	void switch_to_POU_INT();
	int get_stoneval();

	bool operator<(const Stonewt& s) const;
	bool operator>(const Stonewt& s) const;
	bool operator<=(const Stonewt& s) const;
	bool operator>=(const Stonewt& s) const;
	bool operator==(const Stonewt& s) const;
	bool operator!=(const Stonewt& s) const;

	friend Stonewt operator+(const Stonewt& s1, const Stonewt& s2);
	friend Stonewt operator-(const Stonewt& s1, const Stonewt& s2);
	friend Stonewt operator*(const Stonewt& s1, const Stonewt& s2);
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& s);
};

//add an enum member for status and use it in implementation
//add "<<" "+" "-" "*" overload
//add "<" ">" "<=" ">=" "==" "!=" overload
//test all changes
