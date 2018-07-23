#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

inline void show_name(const string& st) { cout << st << ' '; }

int main(void)
{
	set<string> mat_friend;
	set<string> pat_friend;
	cout << "Enter Mat's friends:\n";
	string tmp;
	while (cin >> tmp)
		mat_friend.insert(tmp);
	cin.clear();
	cout << "Enter Pat's friends:\n";
	while (cin >> tmp)
		pat_friend.insert(tmp);
	cout << "Mat's friend name are listed below:\n";
	for_each(mat_friend.begin(), mat_friend.end(), show_name);
	cout << endl;
	cout << "Pat's friend name are listed below:\n";
	for_each(pat_friend.begin(), pat_friend.end(), show_name);
	cout << endl;
	cout << "The union of their friends are listed below:\n";
	set_union(mat_friend.begin(), mat_friend.end(), pat_friend.begin(), pat_friend.end(),
		ostream_iterator<string>(cout, " "));
	cout << endl;
	system("pause");
	return 0;
}