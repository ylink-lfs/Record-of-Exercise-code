#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

const double eps = 1e-6;

struct medicine
{
	int density;
	bool used;
};

bool cmp(medicine, medicine);

inline bool Equ(double a, double b) { return fabs(a - b) < eps; }
inline bool More(double a, double b) { return a - b > eps; }
inline bool Less(double a, double b) { return a - b < -eps; }
inline bool MoreEqu(double a, double b) { return a - b > -eps; }
inline bool LessEqu(double a, double b) { return a - b < eps; }

int main(void)
{
	std::ios::sync_with_stdio(false);
	cout.setf(std::ios_base::fixed);
	cin.tie(nullptr);
	int casis;
	vector<medicine> source_density;
	cin >> casis;
	while (casis--)
	{
		int kind_count;
		int per_volume;
		int density_line;
		int temp_sum = 0;
		cin >> kind_count >> per_volume >> density_line;
		for (int i = 0; i < kind_count; i++)
		{
			medicine cache;
			cin >> cache.density;
			cache.used = false;
			source_density.push_back(cache);
			temp_sum += cache.density;
		}
		sort(source_density.begin(), source_density.end(), cmp);
		if (density_line < source_density[0].density)
		{
			cout << "0 0.00\n";
			source_density.clear();
			continue;
		}
		else
		{
			int current_volume = 0;
			double current_density = 0;
			int index = 0;
			while (index < source_density.size())
			{
				if (More(current_density * current_volume + source_density[index].density * per_volume,
					double(density_line * (current_volume + per_volume))))
				{
					break;
				}
				else
				{
					current_density = (current_density * current_volume + per_volume * source_density[index].density)
						/ (current_volume + per_volume);
					current_volume += per_volume;
					index++;
				}
			}
			double output_density = current_density / 100;
			cout.precision(2);
			cout << current_volume << ' ' << output_density << '\n';
			source_density.clear();
			continue;
		}
	}
	system("pause");
	return 0;
}

bool cmp(medicine a, medicine b)
{
	return a.density < b.density;
}