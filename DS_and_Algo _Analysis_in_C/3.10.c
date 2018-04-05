#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int due(llist_head*, int, int);
void delete_circulate_list(llist_head*, llist_node*);

int main(void)
{
	llist_head* josephus_circle = NULL;
	llist_node* last = NULL;
	int m, n;
	int res;
	int i;

	printf("N people. M times pass. Input M and N for return value:");
	scanf("%d%d", &m, &n);
	josephus_circle = initialize_llist(josephus_circle);
	for (i = 1; i <= n; i++)
	{
		llist_insertion(josephus_circle, i, i);
	}
	last = josephus_circle->next;

	while (last->next)
		last = last->next;
	last->next = josephus_circle->next;
	res = due(josephus_circle, m, n);

	printf("%d\n", res);
	wipe_llist(josephus_circle);
	system("pause");
	return 0;
}

int due(llist_head* plist, int m, int n)
{
	llist_node* current = plist->next;
	llist_node* temp = NULL;
	int i;

	while (plist->counter > 1)
	{
		for (i = 0; i < m; i++)
		{
			current = current->next;
		}
		temp = current;
		current = current->next;
		delete_circulate_list(plist, temp);
	}
	return plist->next->data;
}

void delete_circulate_list(llist_head* plist, llist_node* pnode)
{
	llist_node* previous;
	llist_node* temp;
	int count = 1;
	
	if (plist->counter == 2 && pnode == plist->next)
	{
		temp = pnode;
		plist->next = pnode->next;
		plist->next->next = NULL;
		free(temp);
		plist->counter--;
	}

	else if (plist->counter == 2 && pnode != plist->next)
	{
		free(plist->next->next);
		plist->next->next = NULL;
		plist->counter--;
	}

	else if (pnode == plist->next)
	{
		previous = plist->next;
		while (count < plist->counter)
		{
			previous = previous->next;
			count++;
		}
		temp = pnode;
		previous->next = pnode->next;
		plist->next = temp->next;
		free(temp);
		plist->counter--;
	}
	else
	{
		previous = find_previous(plist, pnode);
		temp = pnode;
		previous->next = temp->next;
		plist->counter--;
		free(temp);
	}
	return;
}