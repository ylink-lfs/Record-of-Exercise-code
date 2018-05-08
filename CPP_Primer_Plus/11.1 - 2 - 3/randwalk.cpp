#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>
#include "vector.h"

int main(void)
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(nullptr));
	
	Vector step;
	Vector result(0.0, 0.0);

	unsigned long steps = 0;
	double direction;
	double target;
	double dstep;

	vector<unsigned long> res;
	ofstream fout;

	fout.open("fuck.txt");

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			fout << steps << ' ' << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		
		cout << "After " << steps << " steps, the subject "
			"Has the following location:\n";
		fout << "After " << steps << " steps, the subject "
			"Has the following location:\n";
		cout << result << endl;
		fout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		fout << "or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		fout << endl;
		res.push_back(steps);
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	sort(res.begin(), res.end());
	int sum = 0;
	for (auto i : res)
		sum += i;
	sum /= res.size();
	fout << "During " << res.size() << " times imitation, the maximum step is " << res[res.size() - 1];
	fout << ", the minimum step is " << res[0] << ", and the average step is " << sum << ".\n";
	cout << "Bye!\n";
	fout << "Log ended\n";
	cin.clear();
	fout.close();
	while (cin.get() != '\n')
		continue;
	system("pause");
	return 0;
}
