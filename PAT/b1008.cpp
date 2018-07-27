//Use todat's newly learned knowledge to reduce the switch times
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(void)
{
	int n, step;
	cin >> n >> step;
	step %= n;

	vector<int> vec(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		
	}
	if (step != 0)
	{
		for (int i = n - step; i < n - step + gcd(step, n); i++)
		{
			int current_index = i;
			int next_index = (i + step) % n;
			int cache = vec[i];
			while (next_index != i)
			{
				swap(cache, vec[next_index]);
				current_index = next_index;
				next_index = (current_index + step) % n;
			}
			swap(cache, vec[next_index]);
		}
	}
	

	//д����ƾֱ�������и����ķ��������......
	//һ�仰��һ���forѭ��Ŷ
	//rotate(vec.begin(), vec.begin() + n - step, vec.end());

	for (int i = 0; i < n; i++)
	{
		cout << vec[i];
		if (i == n - 1)
			cout << endl;
		else
			cout << ' ';
	}


	return 0;

}