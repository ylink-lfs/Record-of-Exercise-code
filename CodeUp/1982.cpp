#include <iostream>
#include <string>
#include <stack>

using std::cin;
using std::cout;
using std::stack;
using std::string;

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int casis;
	string src;
	cin >> casis;
	cin.get();
	while (casis--)
	{
		getline(cin, src);
		stack<char> check;
		string::iterator it = src.begin();
		while (it < src.end())
		{
			if (*it == '(' || *it == '{' || *it == '[')
			{
				check.push(*it);
				it++;
			}
			else if (*it == ')')
			{
				if (!check.empty() && check.top() == '(')
				{
					check.pop();
					it++;
				}
				else
				{
					goto not_match;
				}
			}
			else if (*it == '}')
			{
				if (!check.empty() && check.top() == '{')
				{
					check.pop();
					it++;
				}
				else
				{
					goto not_match;
				}
			}
			else if (*it == ']')
			{
				if (!check.empty() && check.top() == '[')
				{
					check.pop();
					it++;
				}
				else
				{
					goto not_match;
				}
			}
			else
			{
				it++;
			}
		}
		if (check.empty())
		{
			cout << "yes\n";
		}
		else
		{
			not_match:cout << "no\n";
		}
	}

	return 0;
}
