#include <iostream>
#include "10.6a.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::show_coor() const
{
	std::cout << "X: " << x << '\t' << "Y: " << y << '\n';
}

Move Move::merge(const Move& m) const
{
	Move t(this->x + m.x, this->y + m.y);
	return t;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
