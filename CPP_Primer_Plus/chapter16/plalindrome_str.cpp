#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

bool is_plalindrome_str(const string& st);
void wash_string(string& st);
void wipe_nonalnum(string& st);

int main(void)
{
	string src;
	getline(cin, src);
	wash_string(src);
	bool jg = is_plalindrome_str(src);
	cout << jg << endl;
	system("pause");
	return 0;
}

void wash_string(string& st)
{
	transform(st.begin(), st.end(), st.begin(), tolower);
	wipe_nonalnum(st);
}

void wipe_nonalnum(string& st)
{
	for (auto it = st.begin(); it < st.end(); it++)
	{
		if (!isalnum(*it))
		{
			st.erase(it);
			it--;
		}
	}
}

bool is_plalindrome_str(const string& st)
{
	string tmp = st;
	reverse(tmp.begin(), tmp.end());
	return tmp == st;
}
