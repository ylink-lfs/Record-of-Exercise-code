#include <cstdlib>
#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;

void count_queen(vector<vector<int>>& res_container, int(&calculate_board)[100], bool(&hash_table)[100], int colomn, int line);
static int counter = 0;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int line = 8;
	int counting = 0;
	int board[100];
	vector<vector<int>> result_container(92);
	bool hash_it[100] = { false };
	count_queen(result_container, board, hash_it, 1, line);

	int case_num;
	cin >> case_num;
	while (case_num--)
	{
		int n;
		cin >> n;
		n--;
		for (auto i : result_container[n])
			cout << i;
		cout << '\n';
	}

	return 0;
}

void count_queen(vector<vector<int>>& res_container, int(&calculate_board)[100], bool(&hash_table)[100], int colomn, int line)
{
	if (colomn > line)
	{
		for (int i = 1; i <= 8; i++)
		{
			res_container[counter].push_back(calculate_board[i]);
		}
		
		counter++;
		return;
	}
	else
	{
		for (int i = 1; i <= line; i++)
		{
			if (hash_table[i] == false)
			{
				bool available = true;
				for (int j = 1; j <= colomn - 1; j++)
				{
					if (abs(i - calculate_board[j]) == abs(j - colomn))
					{
						available = false;
						break;
					}
				}
				if (available)
				{
					hash_table[i] = true;
					calculate_board[colomn] = i;
					count_queen(res_container, calculate_board, hash_table, colomn + 1, line);
					hash_table[i] = false;
				}
			}
		}
	}
}