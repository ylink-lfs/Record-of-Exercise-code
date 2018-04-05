#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

//return position
void find_elem_recur(llist_node*, int, int*);

int find_elem_nonrecur(llist_head*, int);

int main(void)
{
	int pos1;
	int pos2_count = 0;
	int* pos2 = &pos2_count;
	int i;
	llist_head* test_head = NULL;
	test_head = initialize_llist(test_head);
	for (i = 3; i <= 15000; i += 3)
	{
		llist_insertion(test_head, i, i / 3);
	}
	pos1 = find_elem_nonrecur(test_head, 13000);

	//after 4619-4621 times function call, program broke down
	find_elem_recur(test_head->next, 13000, pos2);

	wipe_llist(test_head);
	system("pause");
	return 0;
}

void find_elem_recur(llist_node* pnode, int elem, int* po)
{
	if (pnode == NULL)
	{
		*po = -1;
		return;
	}
	else if (pnode->data == elem)
	{
		(*po)++;
		return;
	}
	else
	{
		(*po)++;
		find_elem_recur(pnode->next, elem, po);
	}
	
}

int find_elem_nonrecur(llist_head* plist, int elem)
{
	llist_node* current;
	int po = 1;

	if (plist == NULL || plist->counter == 0)
	{
		return -1;
	}
	else
	{
		current = plist->next;
		while (current && current->data != elem)
		{
			current = current->next;
			po++;
		}
		if (current)
		{
			return po;
		}
		else
		{
			return -1;
		}
	}
}