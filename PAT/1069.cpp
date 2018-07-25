#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

struct minus_expression
{
	int minuend;
	int subtractor;
	int result;
	minus_expression(int mi, int sub, int res) : minuend(mi), subtractor(sub), result(res) {}
	friend ostream& operator<<(ostream& os, const minus_expression& me)
	{
		os.width(4);
		os.fill('0');
		os << me.minuend << " - ";
		os.width(4);
		os << me.subtractor << " = ";
		os.width(4);
		return os << me.result;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int start_num = 1;

	while (cin >> start_num)
	{
		if (start_num % 1111 == 0)
		{
			cout << minus_expression(start_num, start_num, 0) << endl;
		}
		else if (start_num == 6174)
		{
			cout << minus_expression(7641, 1467, 6174) << endl;
		}
		else
		{
			int current_num = start_num;
			while (current_num != 6174)
			{
				string num_str1 = to_string(current_num);
				if (num_str1.size() < 4)
					num_str1.insert(num_str1.begin(), 4 - num_str1.size(), '0');
				sort(num_str1.begin(), num_str1.end());

				string num_str2(num_str1);
				reverse(num_str2.begin(), num_str2.end());
				int num1 = stoi(num_str1);
				int num2 = stoi(num_str2);
				current_num = abs(num1 - num2);
				cout << minus_expression(max(num1, num2), min(num1, num2), current_num) << '\n';
			}
		}

	}

	return 0;
}