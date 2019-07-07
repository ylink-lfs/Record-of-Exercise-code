#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>

using namespace std;

string modify(const int n)
{
	auto print_as_it_is = [](const int n) {
		return -999 <= n && n <= 999;
	};
	if (print_as_it_is(n))
	{
		return to_string(n);
	}
	else
	{
		string src(to_string(n));
		int pos = src.size() - 3;
		do
		{
			src.insert(pos, 1, ',');
			pos -= 3;
			if (pos == 1 && src[pos - 1] == '-')
				break;
		} while (pos >= 0 && isdigit(src[pos]));
		return src;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	while (cin >> a >> b)
	{
		int res = a + b;
		cout << modify(res) << '\n';
	}
	return 0;
}