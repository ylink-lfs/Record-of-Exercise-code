#include <stdlib.h>
#include "3.15b1.h"

self_a_list_head* create(self_a_list_head* plist)
{
	plist = (self_a_list_head*)malloc(sizeof(self_a_list_head));
	plist->next = NULL;
	plist->counter = 0;
}

void ask(self_a_list_head* plist, ElementType elem)
{
	llist_node* current = plist->next;
	llist_node* pre;
	ElementType cache;
	while (current && current->data != elem)
	{
		current = current->next;
	}
	if (!current)
	{
		return;
	}
	else
	{
		if (current == plist->next)
		{
			;
		}
		else
		{
			cache = elem;
			while (current != plist->next)
			{
				pre = find_previous(plist, current);
				current->data = pre->data;
				current = pre;
			}
			current->data = cache;
		}
		return;
	}
}