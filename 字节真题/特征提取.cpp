#include <iostream>
#include <vector>
#include <utility>
#include <map>

int main(void)
{
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int cases;
	cin >> cases;
	while (cases--)
	{
		int pix_cnt;
		cin >> pix_cnt;
		vector<vector<pair<int, int>>> pix_container(pix_cnt);
		
		for (int i = 0; i < pix_cnt; i++)
		{
			int feature_cnt;
			cin >> feature_cnt;
			for (int j = 0; j < feature_cnt; j++)
			{
				int x, y;
				cin >> x >> y;
				pix_container[i].push_back(make_pair(x, y));
			}
		}
		vector<map<pair<int, int>, int>> seq_lens(pix_container.size());
		int first_not_zero = 0;
		while (first_not_zero < pix_container.size() && pix_container[first_not_zero].empty())
			first_not_zero++;
		if (first_not_zero == pix_container.size())
		{
			cout << "0\n";
		}
		else
		{
			for (int i = 0; i < pix_container[first_not_zero].size(); i++)
			{
				seq_lens[first_not_zero][pix_container[first_not_zero][i]] = 1;
			}
			for (int i = first_not_zero + 1; i < pix_container.size(); i++)
			{
				for (int j = 0; j < pix_container[i].size(); j++)
				{
					auto cur_pair = pix_container[i][j];
					if (seq_lens[i - 1].find(cur_pair) != seq_lens[i - 1].end())
					{
						seq_lens[i][cur_pair] = seq_lens[i - 1].at(cur_pair) + 1;
					}
					else
					{
						seq_lens[i][cur_pair] = 1;
					}
				}
			}
			int max_len = -1;
			for (const auto& e : seq_lens)
			{
				for (const auto& e1 : e)
				{
					if (max_len < e1.second)
						max_len = e1.second;
				}
			}
			cout << max_len << '\n';
		}
	}
	return 0;
}
