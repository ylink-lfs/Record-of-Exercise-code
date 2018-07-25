#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool judge_characters(const char ch);

int main(void)
{	
	string original_str;
	string pattern_str("PAT");
	int check_num;
	cin >> check_num;

	while (check_num--)
	{
		cin >> original_str;
		int leading_length = 0;
		bool meet_P = false;
		bool unexpected_character = false;
		
		for (auto it = original_str.begin(); it != original_str.end(); it++)
		{
			if (!judge_characters(*it))
			{
				cout << "NO\n";
				unexpected_character = true;
				break;
			}
			if (*it == 'P')
				meet_P = true;
			if (!meet_P && *it == 'A')
				leading_length++;
		}
		if (unexpected_character)
			continue;

		if (original_str.find('T') == string::npos || original_str.find('A') == string::npos)
		{
			cout << "NO\n";
			continue;
		}
		else
		{
			string leading_A(original_str.substr(0, leading_length));
			string operation_str(original_str);
			operation_str.erase(0, leading_A.size());
			

			for (int i = operation_str.size() - 1; operation_str.size() - i - 1 < leading_A.size(); i--)
			{
				if (operation_str[i] != 'A')
				{
					cout << "NO\n";
					unexpected_character = true;
					break;
				}
			}
			if (unexpected_character)
				continue;

			int last_T_pos = operation_str.rfind('T');
			operation_str.erase(operation_str.size() - leading_A.size(), leading_A.size());


			while (operation_str.size() > pattern_str.size())
			{
				bool con1, con2;
				con1 = false;
				con2 = true;
				last_T_pos = operation_str.rfind('T');
				if (operation_str[last_T_pos - 1] == 'A')
					con1 = true;

				for (int i = operation_str.size() - 1; operation_str.size() - i - 1 < leading_A.size(); i--)
				{
					if (operation_str[i] != 'A')
					{
						con2 = false;
						break;
					}
				}

				if (con1 && con2)
				{
					operation_str.erase(last_T_pos - 1, 1);
					operation_str.erase(operation_str.size() - leading_A.size(), leading_A.size());
				}
				else
				{
					break;
				}
			}
			if (operation_str == pattern_str)
			{
				cout << "YES\n";
				continue;
			}
			else
			{
				cout << "NO\n";
				continue;
			}
		}		
	}

	return 0;
}

bool judge_characters(const char ch)
{
	if (ch != 'P' && ch != 'A' && ch != 'T')
		return false;
	else
		return true;
}