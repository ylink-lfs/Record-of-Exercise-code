#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

pair<int, string> manacher(const string& s)
{
	auto initialize = [](const string& s) ->string {
		string res({ char(1), char(2) });
		for (const auto& elem : s) {
			res.push_back(elem);
			res.push_back(char(2));
		}
		res.push_back(char(3));
		return res;
	};
	string handle_str(initialize(s));
	vector<int> radius_range(handle_str.size());
	radius_range[1] = 1;
	int res_halflen = 1, res_index = 1;
	int max_stretch = 1, id = 1;
	for (int i = 2; i < handle_str.size() - 1; i++)
	{
		radius_range[i] = i < max_stretch ? min(max_stretch - i, radius_range[2 * id - i]) : 1;
		while (handle_str[i + radius_range[i]] == handle_str[i - radius_range[i]])
			radius_range[i]++;
		if (max_stretch < i + radius_range[i])
		{
			max_stretch = i + radius_range[i];
			id = i;
		}
		if (res_halflen < radius_range[i])
		{
			res_halflen = radius_range[i];
			res_index = i;
		}
	}
	return make_pair(radius_range[res_index] - 1, s.substr((res_index - res_halflen) / 2, radius_range[res_index] - 1));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s))
	{
		auto result = manacher(s);
		cout << result.first << '\n';
	}
	return 0;
}