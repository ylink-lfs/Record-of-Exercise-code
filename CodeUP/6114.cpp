//need to use hash table for optimizion
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void)
{
	vector<string> courses[2500];
	vector<string> query_list;
	vector<string>::iterator sub_it;
	vector<string>::iterator cmp_it;
	vector<int>::iterator course_it;
	vector<int> cache_course_id;
	int n, k;
	int i, j;
	char cache_fast[5];
	int course_id, course_stu_num;

	string cache;

	while (scanf("%d%d", &n, &k) == 2)
	{
		for (i = 0; i < k; i++)
		{
			scanf("%d%d", &course_id, &course_stu_num);
			for (j = 0; j < course_stu_num; j++)
			{
				scanf("%s", cache_fast);
				courses[course_id - 1].push_back(cache_fast);
			}
		}
		for (i = 0; i < n; i++)
		{
			scanf("%s", cache_fast);
			query_list.push_back(cache_fast);
		}
		//input complete

		sub_it = query_list.begin();
		while (sub_it < query_list.end())
		{

			for (i = 0; i < k; i++)
			{
				cmp_it = courses[i].begin();
				while (cmp_it < courses[i].end())
				{
					if ((*cmp_it) == (*sub_it))
					{
						cache_course_id.push_back(i + 1);
					}
					cmp_it++;
				}
			}
			cout << *sub_it;
			printf(" %d", cache_course_id.size());
			course_it = cache_course_id.begin();
			if (cache_course_id.size() == 0)
			{
				putchar('\n');
			}
			else
			{
				putchar(' ');
				while (course_it < cache_course_id.end())
				{
					cout << *course_it;
					if (course_it == cache_course_id.end() - 1)
					{
						putchar('\n');
					}
					else
					{
						putchar(' ');
					}
					course_it++;
				}
			}
			cache_course_id.clear();
			sub_it++;
		}
		for (i = 0; i < k; i++)
		{
			courses[i].clear();
		}
		query_list.clear();
	}

	return 0;
}