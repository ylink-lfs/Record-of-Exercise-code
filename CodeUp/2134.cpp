#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

struct room
{
	int foot_req;
	int beans;
	double price;
};

bool cmp(room, room);

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.setf(std::ios_base::fixed);
	cout.precision(3);
	int m, n;
	vector<room>room_data;
	while (cin >> m >> n && m != -1)
	{
		for (int i = 0; i < n; i++)
		{
			room cache;
			cin >> cache.beans >> cache.foot_req;
			cache.price = double(cache.foot_req) / cache.beans;
			room_data.push_back(cache);
		}
		sort(room_data.begin(), room_data.end(), cmp);

		double sum_bean = 0;
		double current_food = m;
		int room_iterator = 0;
		while (current_food > 0)
		{
			if (current_food >= room_data[room_iterator].foot_req)
			{
				sum_bean += room_data[room_iterator].beans;
				current_food -= room_data[room_iterator].foot_req;
				room_iterator++;
				continue;
			}
			else
			{
				double ratio = current_food / room_data[room_iterator].foot_req;
				current_food = 0;
				sum_bean += room_data[room_iterator].beans * ratio;
			}
		}
		cout << sum_bean << '\n';
		room_data.clear();
	}
	system("pause");
	return 0;
}

bool cmp(room a, room b)
{
	return a.price < b.price;
}