#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void)
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	string s1, s2;
	int accuracy;
	int e1 = 0, e2 = 0;
	string raw1, raw2;
	cin >> accuracy >> s1 >> s2;
	raw1 = s1; raw2 = s2;

	while (raw1.size() > 0 && *raw1.begin() == '0')
	{
		raw1.erase(raw1.begin());
	}
	while (raw2.size() > 0 && *raw2.begin() == '0')
	{
		raw2.erase(raw2.begin());
	}

	
	if (raw1[0] == '.')
	{
		raw1.erase(raw1.begin());
		while (raw1.size() > 0 && *raw1.begin() == '0')
		{
			raw1.erase(raw1.begin());
			e1--;
		}
	}
	else  
	{
		int wipe_dot = 0;
		while (wipe_dot < raw1.size() && raw1[wipe_dot] != '.')
		{
			wipe_dot++;
			e1++;
		}
		if (wipe_dot < raw1.length())
		{
			raw1.erase(raw1.begin() + wipe_dot);
		}
	}
	if (raw1.length() == 0)
	{
		e1 = 0;
	}
	if (raw2[0] == '.')
	{
		raw2.erase(raw2.begin());
		while (raw2.size() > 0 && *raw2.begin() == '0')
		{
			raw2.erase(raw2.begin());
			e2--;
		}
	}
	else
	{
		int wipe_dot = 0;
		while (wipe_dot < raw2.size() && raw2[wipe_dot] != '.')
		{
			wipe_dot++;
			e2++;
		}
		if (wipe_dot < raw2.length())
		{
			raw2.erase(raw2.begin() + wipe_dot);
		}
	}
	if (raw2.length() == 0)
	{
		e2 = 0;
	}
	if (raw1.size() >= accuracy)
	{
		raw1 = raw1.substr(0, accuracy);
	}
	else
	{
		while (raw1.size() < accuracy)
		{
			raw1 += "0";
		}
	}
	if (raw2.size() >= accuracy)
	{
		raw2 = raw2.substr(0, accuracy);
	}
	else
	{
		while (raw2.size() < accuracy)
		{
			raw2 += "0";
		}
	}
	if (raw1 == raw2 && e1 == e2)
	{
		cout << "YES" << ' ' << "0." << raw1 << "*10^" << e1 << endl;
	}
	else
	{
		cout << "NO" << ' ' << "0." << raw1 << "*10^" << e1 << ' '
			<< "0." << raw2 << "*10^" << e2 << endl;
	}
	system("pause");
	return 0;
}