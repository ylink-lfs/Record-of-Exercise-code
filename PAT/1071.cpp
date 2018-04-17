//without inline, this code can pass PAT judger. with inline, this code cannot pass CodeUp judger
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;
inline bool check_alnum(char c) {
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	else
		return false;
}
inline bool check_upper(char c) {
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}
inline bool check_lower(char c){
	if (c >= 'a' && c <= 'z')
		return true;
	else
		return false;
}

int main(void)
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	string read_word;
	char ch = 'd';

	map<string, int> mymap;
	while (ch != '\n' && (ch = cin.get()) != '\n')
	{
		if (!check_alnum(ch))
		{
			continue;
		}
		else
		{
			if (check_upper(ch))
			{
				ch += 32;
			}
			read_word += ch;
			while (check_alnum(ch = cin.get()))
			{
				if (check_upper(ch))
				{
					ch += 32;
				}
				read_word += ch;
			}
		}
		if (mymap.find(read_word) != mymap.end())
		{
			mymap[read_word]++;
		}
		else
		{
			mymap[read_word] = 1;
		}
		read_word.clear();

	}
	string max_str = mymap.begin()->first;
	int max_cache = mymap.begin()->second;
	for (auto it = mymap.begin(); it != mymap.end(); it++)
	{
		if (max_cache < it->second)
		{
			max_str = it->first;
			max_cache = it->second;
		}
	}
	cout << max_str << ' ' << max_cache << endl;
	return 0;
	
}