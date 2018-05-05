#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int src[90];

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int casis;
	while (cin >> casis)
	{
		while (casis--)
		{
			int total;
			cin >> total;
			for (int i = 0; i < total; i++)
			{
				cin >> src[i];
			}
			int index;
			vector<int> res;
			for (index = 0; index < total; index++)
			{
				if (index >= 1 && index <= total - 2)
				{
					if ((src[index] > src[index - 1] &&
						src[index] > src[index + 1]) || (src[index] < src[index - 1] &&
							src[index] < src[index + 1]))
					{
						res.push_back(index);
					}
				}
				else if (index == 0)
				{
					if (total > 1 && src[index] != src[index + 1])
					{
						res.push_back(index);
					}
				}
				else if (index == total - 1)
				{
					if (total > 1 && src[index] != src[index - 1])
					{
						res.push_back(index);
					}
				}
			}

			for (auto it = res.begin(); it != res.end(); it++)
			{
				cout << *it;
				if (it + 1 == res.end())
				{
					cout << '\n';
				}
				else
				{
					cout << ' ';
				}
			}
			res.clear();
		}
	}
	

	return 0;
}
