#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> lotto(const int dot_count, const int winner_num);

int main(void)
{
	vector<int> winners(lotto(51, 6));
	for (const auto& it : winners)
		cout << it << ' ';
	cout << endl;
	copy(winners.begin(), winners.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cin.get();
	return 0;
}

vector<int> lotto(const int dot_count, const int winner_num)
{
	vector<int> src_vec(dot_count);
	for (auto it = src_vec.begin(); it < src_vec.end(); it++)
		*it = it - src_vec.begin() + 1;
	random_shuffle(src_vec.begin(), src_vec.end());
	return vector<int>(src_vec.begin(), src_vec.begin() + winner_num);
}