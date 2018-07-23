#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T>
int reduce(T* ar, int n);

int main(void)
{
	long test_ar[10] = { 3, 5, 5, 2, 6, 7, 8, 10, 10, 1 };
	int new_len = reduce(test_ar, 10);
	cout << new_len << endl;

	string test_st[10] = 
	{
		"adam", "cyper", "ecoly", "cyper", "pser",
		"oytu", "pser", "hifi", "cyper", "playful"
	};
	new_len = reduce(test_st, 10);
	cout << new_len << endl;
	cin.get();
	return 0;
}

//Sort the given array and remove duplicate elements
//Return element count after unique process
template <typename T>
int reduce(T* ar, int n)
{
	sort(ar, ar + n);
	const T* new_end = unique(ar, ar + n);
	return new_end - ar;
}