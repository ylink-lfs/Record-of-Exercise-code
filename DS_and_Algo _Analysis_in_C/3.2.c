#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void PrintLots(llist_head*, llist_head*);

int main(void)
{
	llist_head* l = NULL;
	llist_head* p = NULL;
	int i;

	l = initialize_llist(l);
	p = initialize_llist(p);
	llist_insertion(p, 1, 1);
	llist_insertion(p, 3, 2);
	llist_insertion(p, 4, 3);
	llist_insertion(p, 6, 4);

	for (i = 2; i <= 20; i+=2)
	{
		llist_insertion(l, i, i / 2);
	}
	PrintLots(l, p);

	wipe_llist(l); wipe_llist(p);
	system("pause");
	return 0;
}

void PrintLots(llist_head* p, llist_head* q)
{
	llist_node* current_p;
	llist_node* current_q;
	int count_p = 1;
	current_p = p->next;
	current_q = q->next;
	while (current_q)
	{
		for (; count_p < current_q->data; count_p++)
		{
			current_p = current_p->next;
		}
		printf("%d ", current_p->data);
		current_q = current_q->next;
	}
	putchar('\n');
	return;
}