#include <cstdio>
#include <set>
#include <cstdlib>
#include <cstring>

using namespace std;
set<int>set_arr[55];


int main(void)
{

	int total_set;
	int set_item_count;
	int cache;

	scanf("%d", &total_set);
	for (int i = 0; i < total_set; i++)
	{
		scanf("%d", &set_item_count);
		for (int j = 0; j < set_item_count; j++)
		{
			scanf("%d", &cache);
			set_arr[i].insert(cache);
		}
	}
	
	set<int>::iterator it;
	int total_query;
	int query_id1, query_id2;
	int bottom_num1;
	double bottom_num;
	int same_count;
	double res;

	scanf("%d", &total_query);
	for (int i = 0; i < total_query; i++)
	{
		scanf("%d%d", &query_id1, &query_id2);
		query_id1--;
		query_id2--;
		same_count = 0;
		bottom_num1 = set_arr[query_id1].size();
		for (it = set_arr[query_id2].begin(); it != set_arr[query_id2].end(); it++)
		{
			if (set_arr[query_id1].find(*it) != set_arr[query_id1].end())
			{
				same_count++;
			}
			else
			{
				bottom_num1++;
			}
		}
		bottom_num = bottom_num1;
		res = 100 * same_count / bottom_num;
		printf("%.1f%%\n", res);
	}

	return 0;
}
