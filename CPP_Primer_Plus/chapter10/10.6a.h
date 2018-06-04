#pragma once
class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void show_coor() const;
	Move merge(const Move& m) const;
	void reset(double a = 0, double b = 0);
};
