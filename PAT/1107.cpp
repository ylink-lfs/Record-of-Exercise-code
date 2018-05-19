#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int father[1010];
int course[1010];
int is_root[1010];

void initialize_ufs(void);
int find_father(int elem_index);
void unionize(int elem_index1, int elem_index2);

bool cmp(int a, int b) { return a > b; }

int main(void)
{
	int n;
	initialize_ufs();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int hobby_count;
		scanf("%d", &hobby_count);
		getchar();
		is_root[i] = 1;
		for (int j = 0; j < hobby_count; j++)  //just stands for reading j times
		{
			int hobby_id;
			scanf("%d", &hobby_id);
			if (course[hobby_id] == 0)
			{
				course[hobby_id] = i;
			}
			unionize(find_father(course[hobby_id]), i);
		}
	}
	sort(is_root + 1, is_root + n + 1, cmp);
	int counter = 0;
	for (int i = 1; is_root[i] != 0; i++)
	{
		counter++;
	}
	printf("%d\n", counter);
	for (int i = 1; i <= counter; i++)
	{
		printf("%d", is_root[i]);
		if (i == counter)
			putchar('\n');
		else
			putchar(' ');
	}

	return 0;
}

void initialize_ufs(void)
{
	for (int i = 0; i < 1010; i++)
	{
		is_root[i] = 0;
		father[i] = i;
	}
	return;
}

int find_father(int elem_index)
{
	int res = elem_index;
	while (res != father[res])
	{
		res = father[res];
	}
	return res;
}

void unionize(int elem_index1, int elem_index2)
{
	int root1 = find_father(elem_index1);
	int root2 = find_father(elem_index2);
	if (root1 != root2)
	{
		is_root[root1] += is_root[root2];
		is_root[root2] = 0;
		father[root2] = root1;
	}
	return;
}
