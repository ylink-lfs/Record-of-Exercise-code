#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <vector>



using namespace std;



int name_hash(char*); // difference

const int max_elem = 26 * 26 * 26 * 10 + 1;

vector<int>course_select[max_elem];



int main(void)

{

	int query_total, course_num;

	int stu_course, course_id;



	char cache_name[5];

	int name_int_cache;

	int i, j;



	scanf("%d%d", &query_total, &course_num);





	for (i = 0; i < course_num; i++)

	{

		scanf("%d%d", &course_id, &stu_course);

		for (j = 0; j < stu_course; j++)

		{

			scanf("%s", cache_name);

			course_select[name_hash(cache_name)].push_back(course_id);

		}

	}

	for (i = 0; i < query_total; i++)

	{

		scanf("%s", cache_name);

		printf("%s ", cache_name);

		name_int_cache = name_hash(cache_name);



		printf("%d", course_select[name_int_cache].size());

		sort(course_select[name_int_cache].begin(), course_select[name_int_cache].end());



		for (int m = 0; m < course_select[name_int_cache].size(); m++)

		{

			printf(" %d", course_select[name_int_cache][m]);

		}

		printf("\n");

	}

	return 0;

}



int name_hash(char* name)

{

	return (name[0] - 'A') * 26 * 26 * 10 + 

		(name[1] - 'A') * 26 *10 + (name[2] - 'A') * 10 + name[3] - '0';

}
//only use standard stdio(scanf and printf): 111ms in the largest data set
//raw io stream: time limit exceed in the largest data set
//only optimise input stream: time limit exceed too
//optimise input and output stream with ios::sync_with_stdio: 99ms, faster than the first!!!
//what if we change '\n' to endl? : 162ms, what the fuck...
//use string object instead of char array, use a copy of each string object: about 160ms
//use reference of a string and io optimization: 111ms
//If use inline, this behavior contrinutes 3ms optimization...
