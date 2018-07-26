#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string num;
	cin >> num;
	int pos = 1;
	int t_pos = 0;
	int rpos = num.size() - 1;
	int tot = 0;
	while (rpos >= 0)
	{
		string left(num.substr(0, num.size() - t_pos - 1));
		string right;
		if (rpos != num.size() - 1)
		{
			right = num.substr(rpos + 1, num.size() - rpos - 1);
		}
		int left_num = left.size() == 0 ? 0 : stoi(left);
		int right_num = right.size() == 0 ? 0 : stoi(right);
		int cur_pos = num[rpos] - '0';
		switch (cur_pos)
		{
		case 0:
			tot += left_num * pos;
			break;
		case 1:
			tot += left_num * pos + (right_num + 1);
			break;
		default:
			tot += (left_num + 1) * pos;
			break;
		}

		rpos--;
		pos *= 10;
		t_pos++;
	}
	cout << tot << endl;
	system("pause");
	return 0;
}