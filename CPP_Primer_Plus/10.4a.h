#pragma once

namespace SALES
{
	class Sales
	{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales();
		Sales(const double array[], int n = 0);
		void show() const;
	};
}