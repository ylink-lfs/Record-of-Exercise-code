#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int huge = 1000000;

int main(void)
{
	srand(time(nullptr));
	vector<int> vi0(huge);
	for (auto& n : vi0)
		n = rand();
	vector<int> vi(vi0);
	list<int> li;
	//If error occurs, resize li first
	li.assign(vi0.begin(), vi0.end());
	double t1 = clock();
	sort(vi.begin(), vi.end());
	double t2 = clock();
	cout << "vector sort duration: " << (t2 - t1) / CLOCKS_PER_SEC << endl;
	t1 = clock();
	li.sort();
	t2 = clock();
	cout << "list sort duration: " << (t2 - t1) / CLOCKS_PER_SEC << endl;

	li.clear();
	li.assign(vi0.begin(), vi0.end());
	t1 = clock();
	vi.assign(li.begin(), li.end());
	sort(vi.begin(), vi.end());
	t2 = clock();
	cout << "hybrid sort duration: " << (t2 - t1) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}