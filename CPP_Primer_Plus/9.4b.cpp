#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "Header.h"

static double max_of4(double* ar, int n)
{
	using std::sort;
	sort(ar, ar + n);
	return ar[n - 1];
}

namespace SALES
{
	using std::cout;
	using std::cin;
	using std::endl;
	void setSales(Sales & s, const double ar[], int n)
	{
		s.max = s.min = s.average = 0;
		double* cache = new double[n];
		double sum = 0;

		s.sales[0] = s.sales[1] = s.sales[2] = s.sales[3] = 0;
		for (int i = 0; i < n; i++)
		{
			s.sales[i] = ar[i];
			cache[i] = ar[i];
		}
		s.max = max_of4(cache, n);
		s.min = cache[0];
		for (int i = 0; i < n; i++)
		{
			sum += ar[i];
		}
		sum /= n;
		s.average = sum;
		delete[]cache;
		return;
	}
	
	void setSales(Sales & s)
	{
		using std::cout;
		using std::cin;
		using std::endl;

		cout << "Enter fucking four sale amount:";
		cin >> s.sales[0] >> s.sales[1] >> s.sales[2] >> s.sales[3];
		double* cache = new double[4];
		double sum = 0;

		for (int i = 0; i < 4; i++)
		{
			cache[i] = s.sales[i];
		}
		s.max = max_of4(cache, 4);
		s.min = cache[0];
		for (int i = 0; i < 4; i++)
		{
			sum += s.sales[i];
		}
		sum /= 4;
		s.average = sum;
		delete[]cache;
		return;
	}

	void showSales(const Sales & s)
	{
		cout << "Sales:" << endl;
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Quarter " << i + 1 << ": " << s.sales[i] << endl;
		}
		cout << "Avg: " << s.average << endl;
		cout << "Max: " << s.max << endl;
		cout << "Min " << s.min << endl;
		return;
	}
}