#include <iostream>
#include <cstdlib>
#include <string>

using std::string;

//1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo->hello
//2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo->hello
//3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC
void fix(string& s)
{
	auto scanner = s.begin();
	auto check_three_same_char = [](string& s, string::iterator it)->bool {
		if (s.end() - it <= 2)
			return false;
		else
		{
			bool check_flag = true;
			char check_char = *it;
			for (auto subit = it; subit < it + 3; subit++)
			{
				if (check_char != *subit)
				{
					check_flag = false;
					break;
				}
			}
			return check_flag;
		}
	};
	auto check_two_pair_char = [](string& s, string::iterator it)->bool {
		if (s.end() - it < 4)
			return false;
		else
		{
			if (*it == *(it + 1) && *(it + 2) == *(it + 3))
			{
				return true;
			}
			return false;
		}
	};
	while (scanner < s.end())
	{
		bool three_same_res, two_pair_res;
		while (three_same_res = check_three_same_char(s, scanner))
		{
			scanner = s.erase(scanner);
		}
		while (two_pair_res = check_two_pair_char(s, scanner))
		{
			scanner = s.erase(scanner + 2);
			scanner -= 2;
		}
		if (!three_same_res && !two_pair_res)
			scanner++;
	}
}

int main(void)
{
	using namespace std;
	string input;
	int n;
	cin >> n;
	cin.get();
	while (n--)
	{
		getline(cin, input);
		fix(input);
		cout << input << '\n';
	}
	cin.get();
	return 0;
}
