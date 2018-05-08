#include <iostream>
#include <vector>
#include <cstdlib>
#include "stonewt.h"

using std::cin;
using std::cout;
using std::vector;

bool check_stone(Stonewt& ob);

int main(void)
{
	Stonewt test_arr[6] = { {50}, {60.6}, {70} };
	for (int i = 0; i < 3; i++)
	{
		double cache;
		cin >> cache;  //test input: 80 90 100
		test_arr[i + 3] = cache;
	}
	int bigger_than_11 = 0;
	for (int i = 0; i < 6; i++)
	{
		if (check_stone(test_arr[i]))
			bigger_than_11++;
	}
	test_arr[0] = test_arr[0] + test_arr[1];
	test_arr[2] = test_arr[1] - test_arr[2];
	test_arr[3] = test_arr[3] * test_arr[4];
	bool status_arr[6];
	status_arr[0] = test_arr[0] < test_arr[1];
	status_arr[1] = test_arr[0] > test_arr[1];
	status_arr[2] = test_arr[0] >= test_arr[1];
	status_arr[3] = test_arr[0] <= test_arr[1];
	status_arr[4] = test_arr[0] == test_arr[1];
	status_arr[5] = test_arr[0] != test_arr[1];

	cout << "pre_order_str" << test_arr[0] << std::endl;
	
	//how to switch?
	test_arr[1].switch_to_POU_INT();

	cout << test_arr[1] << std::endl;
	system("pause");
	return 0;
}

bool check_stone(Stonewt& ob)
{
	if (ob.get_stoneval() >= 11)
		return true;
	else
		return false;
}