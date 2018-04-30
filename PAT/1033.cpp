#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

struct station_info
{
	double price;
	double distance;
};

bool cmp(station_info, station_info);

station_info all_station[505];

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.setf(std::ios_base::fixed);
	cout.precision(2);

	double tank_capacity, total_distance, distance_per_volume;
	int station_num;
	cin >> tank_capacity >> total_distance >> distance_per_volume >> station_num;

	double distance_per_tank = tank_capacity * distance_per_volume;
	for (int i = 0; i < station_num; i++)
	{
		cin >> all_station[i].price >> all_station[i].distance;
	}
	std::sort(all_station, all_station + station_num, cmp);
	if (station_num == 0 || all_station[0].distance != 0)
	{
		cout << "The maximum travel distance = 0.00\n";
	}
	else
	{
		all_station[station_num] = { 0.0, total_distance };
		station_num++;
		

		double current_volume = 0;
		double current_price = 0;
		double current_distance = 0;

		int current_index = 0;

		while (current_distance < total_distance)
		{
			if (all_station[current_index].distance + distance_per_tank < all_station[current_index + 1].distance)
			{
				current_distance += distance_per_tank;
				current_price += (tank_capacity - current_volume) * all_station[current_index].price;
				current_volume = 0;
				break;
			}

			int min_index = current_index + 1;
			int temp_iterator = min_index;

			double distance_upper_bound = (all_station[current_index].distance + distance_per_tank) >
				total_distance ? total_distance : (all_station[current_index].distance + distance_per_tank);

			double distance_iterator = all_station[temp_iterator].distance;
			while (temp_iterator < station_num && distance_iterator <= distance_upper_bound)
			{
				if (all_station[temp_iterator].price < all_station[current_index].price)
				{
					min_index = temp_iterator;
					break;
				}
				if (all_station[min_index].price > all_station[temp_iterator].price)
					min_index = temp_iterator;
				temp_iterator++;
				distance_iterator = all_station[temp_iterator].distance;
			}

			double dif = all_station[min_index].distance - all_station[current_index].distance;

			if (all_station[current_index].price < all_station[min_index].price)
			{
				//add to full
				current_price += (tank_capacity - current_volume) * all_station[current_index].price;
				current_volume = tank_capacity - (dif / distance_per_volume);
				current_distance = all_station[min_index].distance;
			}
			else
			{
				if (current_volume * distance_per_volume >= dif)
				{
					//don't add oil
					current_volume = current_volume - (dif / distance_per_volume);
					current_distance = all_station[min_index].distance;
				}
				else
				{
					//add oil just needed
					current_price += (dif - (current_volume * distance_per_volume)) * all_station[current_index].price / distance_per_volume;
					current_volume = 0;
					current_distance = all_station[min_index].distance;
				}
			}
			current_index = min_index;
		}

		
		
		if (current_distance < total_distance)
		{
			cout << "The maximum travel distance = " << current_distance << '\n';
		}
		else
		{
			cout << current_price << '\n';
		}
	}

	return 0;
}

bool cmp(station_info a, station_info b)
{
	return a.distance < b.distance;
}
