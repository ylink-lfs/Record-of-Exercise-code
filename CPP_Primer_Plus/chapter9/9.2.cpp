#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
const int ArSize = 10;

void strcount(const string&);

int main(void)
{

	string input;
	char next;
	cout << "Enter a line:\n";

	while (getline(cin, input))
	{
		if (input == "")
		{
			break;
		}
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
	}
	cout << "Bye\n";
	return 0;
}

void strcount(const string& str)
{
	using namespace std;
	string cache = str;
	char* search = &cache[0];
	static int total = 0;        // static local variable
	int count = 0;               // automatic local variable
	cout << "\"" << str << "\" contains ";
	while (*search++)               // go to end of string
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
