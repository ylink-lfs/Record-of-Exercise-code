#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

inline int name_hash(char* name) {
	return (name[0] - 'A') * 26 * 26 * 10 +
		(name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + name[3] - '0';
}
const int max_stu_hash = 26 * 26 * 26 + 10;
const int max_course = 2500;

char* hash_return(int, char*);
vector<int>course_stu[max_course];

int main(void)
{
	int n, k;
	char cache[5];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", cache);
		int hash_id = name_hash(cache);
		int class_pick;
		scanf("%d", &class_pick);
		for (int j = 0; j < class_pick; j++)
		{
			int class_id;
			scanf("%d", &class_id);
			course_stu[class_id - 1].push_back(hash_id);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d %d\n", i + 1, course_stu[i].size());
		sort(course_stu[i].begin(), course_stu[i].end());
		char* cache2 = (char*)malloc(sizeof(char) * 5);
		for (int j = 0; j < course_stu[i].size(); j++)
		{
			cache2 = hash_return(course_stu[i][j], cache2);
			if (cache2 == NULL)
			{
				break;
			}
			printf("%s\n", cache2);
		}
		free(cache2);
	}
	system("pause");
	return 0;
}

char* hash_return(int num, char* name)
{

	int temp;
	name[4] = '\0';
	temp = num % 10;
	name[3] = temp + '0';
	num /= 10;
	temp = num % 26;
	name[2] = temp + 'A';
	num /= 26;
	temp = num % 26;
	name[1] = temp + 'A';
	num /= 26;
	temp = num;
	name[0] = temp + 'A';
	return name;
}