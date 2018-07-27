#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(void)
{
	
	int a, b;
	while (cin >> a >> b)
	{
		cout << gcd(a, b) << endl;
	}

	return 0;
}