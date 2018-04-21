#include <cstdlib>
#include <iostream>
#include "10.4a.h"

namespace SALES
{
	using std::cout;
	using std::cin;
	using std::endl;

	Sales::Sales()
	{
		double t_arr[QUARTERS];
		cout << "You must intilize object. Start initialization.\n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Season " << i + 1 << " sales: ";
			cin >> t_arr[i];
		}
		cout << endl;
		Sales temp(t_arr, 4);
		*this = temp;
	}

	Sales::Sales(const double arr[], int n)
	{
		if (n < 4)
		{
			std::cerr << "Notice that element num is less than 4\n";
		}
		double max = arr[0];
		double min = arr[0];
		double sum = 0;
		int i;
		for (i = 0; i < n; i++)
		{
			this->sales[i] = arr[i];
			sum += arr[i];
			if (max < arr[i])
				max = arr[i];
			if (min > arr[i])
				min = arr[i];
		}
		this->max = max;
		this->min = min;
		if (n > 0 && n < 4)
		{
			this->average = sum / n;
			for (; i < 4; i++)
				this->sales[i] = 0;
		}
		else if (n == 4)
			this->average = sum / n;
		else
			this->average = 0;
	}

	void Sales::show() const
	{
		cout << "Sales:" << endl;
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "Quarter " << i + 1 << ": " << sales[i] << endl;
		}
		cout << "Avg: " << average << endl;
		cout << "Max: " << max << endl;
		cout << "Min " << min << endl;
		cout << endl;
		return;
	}
}