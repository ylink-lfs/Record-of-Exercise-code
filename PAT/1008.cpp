#include <iostream>
#include <cmath>

using namespace std;

const int up_time = 6;
const int down_time = 4;
const int waiting_time = 5;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int move_times;
	while (cin >> move_times)
	{
		int tot_time = 0;
		int pre_floor = 0;
		for (int times = 0; times < move_times; times++)
		{
			int cur_floor;
			cin >> cur_floor;
			
			//Go up
			if (cur_floor > pre_floor)
			{
				tot_time += (cur_floor - pre_floor) * up_time + waiting_time;				
			}
			//Go down
			else if (cur_floor < pre_floor)
			{
				tot_time += (pre_floor - cur_floor) * down_time + waiting_time;
			}
			//No move
			else
			{
				tot_time += waiting_time * 2;
			}
			pre_floor = cur_floor;
		}
		cout << tot_time << '\n';
	}
	return 0;
}