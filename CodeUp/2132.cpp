#include <iostream>
#include <cstdlib>
#include <algorithm>

int brickdata[600];

using std::cin;
using std::cout;
using std::sort;

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int crack_length, brick_count;
	int sum_brick_length;
	while (cin >> crack_length >> brick_count)
	{
		sum_brick_length = 0;
		for (int i = 0; i < brick_count; i++)
		{
			cin >> brickdata[i];
			sum_brick_length += brickdata[i];
		}
		if (sum_brick_length < crack_length)
		{
			cout << "impossible\n";
			continue;
		}
		else if (sum_brick_length == crack_length)
		{
			cout << brick_count << '\n';
			continue;
		}
		else
		{
			sort(brickdata, brickdata + brick_count);
			int rest_len = crack_length;
			int sub_counter = 0;
			int current_index = brick_count - 1;
			while (rest_len > 0)
			{
				if (brickdata[current_index] > rest_len)
				{
					sub_counter++;
					break;
				}
				else
				{
					sub_counter++;
					rest_len -= brickdata[current_index];
					current_index--;
				}
			}
			cout << sub_counter << '\n';
		}
	}
	return 0;
}