#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

//counting range from -49999-50000, 
//change hash table and specific adjusting value for bigger range
bool hash_table1[100000];
bool hash_table2[100000];
llist_head* intersection_set(llist_head*, llist_head*);


int main(void)
{
	int i;
	int position_counter;
	int res_length;

	llist_node* traversal = NULL;
	llist_head* l1 = NULL;
	llist_head* l2 = NULL;
	llist_head* lres = NULL;

	l1 = initialize_llist(l1);
	l2 = initialize_llist(l2);
	lres = initialize_llist(lres);
	memset(hash_table1, false, sizeof(bool));
	memset(hash_table2, false, sizeof(bool));

	position_counter = 1;
	for (i = 2; i < 100; i += 2)
	{
		llist_insertion(l1, i, position_counter);
		position_counter++;
	}

	position_counter = 1;
	for (i = 3; i < 100; i += 3)
	{
		llist_insertion(l2, i, position_counter);
		position_counter++;
	}

	lres = intersection_set(l1, l2);

	res_length = lres->counter;
	traversal = lres->next;
	for (i = 0; i < res_length; i++)
	{
		printf("%d ", traversal->data);
		traversal = traversal->next;
	}
	putchar('\n');
	wipe_llist(l1);
	wipe_llist(l2);
	wipe_llist(lres);

	system("pause");
	return 0;
}

llist_head* intersection_set(llist_head* p, llist_head* q)
{
	llist_head* dummy = NULL;
	llist_node* traverse;
	int i;
	int insertion_counter = 1;
	if (p == NULL && q == NULL)
	{
		;
	}
	else if (p == NULL || q == NULL)
	{
		dummy = p ? p : q;
	}
	else
	{
		if (p->counter == 0 || q->counter == 0)
		{
			dummy = p->counter == 0 ? q : p;
		}
		else
		{
			dummy = initialize_llist(dummy);
			traverse = p->next;
			while (traverse)
			{
				hash_table1[traverse->data + 49999] = true;
				traverse = traverse->next;
			}
			traverse = q->next;
			while (traverse)
			{
				hash_table2[traverse->data + 49999] = true;
				traverse = traverse->next;
			}
			for (i = 0; i < 100000; i++)
			{
				if (hash_table1[i] || hash_table2[i])
				{
					llist_insertion(dummy, i - 49999, insertion_counter);
					insertion_counter++;
				}
			}
		}
	}
	return dummy;
}