//坑爹题！
#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int elem_count;
	cin >> elem_count;
	double sum = 0;
	
	for (int times = 1; times <= elem_count; times++)
	{
		double tmp_num;
		cin >> tmp_num;
		sum += tmp_num * times * (elem_count + 1 - times);
	}


	cout.setf(ios_base::fixed);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout << sum << '\n';

	return 0;
}
