#include <iostream>
#include "stonewt.h"

Stonewt::Stonewt(double lbs)  //total weight = lbs(pounds)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn;
	pounds = lbs;
	cur_status = POUNDS_FLT;
}

Stonewt::Stonewt(int stn, double lbs)  //total weight = stn(stones) + lbs(pounds)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn;
	cur_status = STONE;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	cur_status = POUNDS_FLT;
}

Stonewt::~Stonewt()
{
}

void Stonewt::switch_to_STONE()
{
	cur_status = STONE;
}

void Stonewt::switch_to_POU_FLT()
{
	cur_status = POUNDS_FLT;
}

void Stonewt::switch_to_POU_INT()
{
	cur_status = POUNDS_INT;
}

int Stonewt::get_stoneval()
{
	return stone;
}

bool Stonewt::operator<(const Stonewt& s) const
{
	return pounds < s.pounds;
}

bool Stonewt::operator>(const Stonewt& s) const
{
	return pounds > s.pounds;
}

bool Stonewt::operator<=(const Stonewt& s) const
{
	return pounds <= s.pounds;
}

bool Stonewt::operator>=(const Stonewt& s) const
{
	return pounds >= s.pounds;
}

bool Stonewt::operator==(const Stonewt& s) const
{
	return pounds == s.pounds;
}

bool Stonewt::operator!=(const Stonewt& s) const
{
	return pounds != s.pounds;
}

Stonewt operator+(const Stonewt& s1, const Stonewt& s2)
{
	return Stonewt(s1.pounds + s2.pounds);
}

Stonewt operator-(const Stonewt& s1, const Stonewt& s2)
{
	return Stonewt(s1.pounds - s2.pounds);
}

Stonewt operator*(const Stonewt& s1, const Stonewt& s2)
{
	return Stonewt(s1.pounds * s2.pounds);
}

std::ostream& operator<<(std::ostream& os, const Stonewt& s)
{
	if (s.cur_status == Stonewt::STONE)
	{
		os << "Weight in stone: " << s.stone << "\tLeft pounds: " << s.pds_left;
	}
	else if (s.cur_status == Stonewt::POUNDS_FLT)
	{
		os << "Weight in pounds(float format): " << s.pounds;
	}
	else if (s.cur_status == Stonewt::POUNDS_INT)
	{
		os << "Weight in pounds(integer format): " << int(s.pounds);
	}
	else
	{
		os << "Object is currently in invalid status";
	}
	return os;
}