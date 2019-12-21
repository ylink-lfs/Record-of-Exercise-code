#include <iostream>
#include <vector>

int maxd, building_count;
std::vector<int> dist(1000000);

int main(void)
{
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> building_count >> maxd)
	{
		if (building_count < 3)
		{
			cout << "0\n";
		}
		else
		{
			for (int i = 0; i < building_count; i++)
			{
				int t;
				cin >> t;
				dist[i] = t;
			}
			unsigned long long solution_count = 0;
			int window_bg = 0, window_ed = 2;
			while (window_ed < building_count)
			{
				while (window_bg < window_ed - 2 && dist[window_ed] - dist[window_bg] > maxd)
				{
					window_bg++;
				}
				if (dist[window_ed] - dist[window_bg] <= maxd)
				{
					unsigned long long second_choice_num = window_ed - window_bg;
					second_choice_num %= 99997867;
					if (second_choice_num % 2 == 0)
					{
						solution_count += second_choice_num / 2 * (second_choice_num - 1) % 99997867;
					}
					else
					{
						solution_count += (second_choice_num - 1) / 2 * second_choice_num % 99997867;
					}
					solution_count %= 99997867;
				}
				window_ed++;
			}
			cout << solution_count << '\n';
		}
	}
	return 0;
}
