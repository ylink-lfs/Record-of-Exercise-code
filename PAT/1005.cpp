#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

unordered_map<char, string> mp = {
	make_pair('1', "one"),
	make_pair('2', "two"),
	make_pair('3', "three"),
	make_pair('4', "four"),
	make_pair('5', "five"),
	make_pair('6', "six"),
	make_pair('7', "seven"),
	make_pair('8', "eight"),
	make_pair('9', "nine"),
	make_pair('0', "zero"),
};

string modify(const int n)
{
	string src(to_string(n));
	string res;
	for (int i = 0; i < src.size(); i++)
	{
		res.insert(res.size(), mp[src[i]]);
		if (i == src.size() - 1)
			break;
		else
			res.insert(res.size(), 1, ' ');
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string num;
	while (cin >> num)
	{
		int sum = 0;
		for (int i = 0; i < num.size(); i++)
		{
			sum += num[i] - '0';
		}
		cout << modify(sum) << '\n';
	}
	return 0;
}