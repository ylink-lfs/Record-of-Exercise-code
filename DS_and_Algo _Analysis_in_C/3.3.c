//"position" is defined to be the first node wait for swap. Example: given position value 1,
//then node 1 and node 2 will be swapped

//single link solution
#include <stdlib.h>
#include "linked_list.h"
void exchange_elem(llist_head* plist, int position)
{
	llist_node* pre;
	llist_node* given;
	llist_node* given_next;

	llist_node* pnew1;
	llist_node* pnew2;
	llist_node* temp1;
	llist_node* temp2;

	int i;
	//invalid position
	if (position <= 0 || position >= plist->counter)
	{
		return;
	}
	//empty head or no elem or just one elem
	if (plist == NULL || plist->next == NULL || plist->next->next == NULL)
	{
		return;
	}

	//land "given" ptr on the specific position
	given = plist->next;
	for (i = 1; i < position; i++)
	{
		given = given->next;
	}

	pnew1 = (llist_node*)malloc(sizeof(llist_node));
	pnew2 = (llist_node*)malloc(sizeof(llist_node));
	pnew1->next = pnew2->next = NULL;

	//differnet previous node kind, so use two branch to complete exchange
	if (position == 1)
	{
		given_next = given->next;
		temp1 = given;
		temp2 = given_next;

		pnew1->data = given->data;
		pnew2->data = given_next->data;
		pnew2->next = pnew1;
		pnew1->next = given_next->next;

		plist->next = pnew2;
		free(given);
		free(given_next);
	}
	else
	{
		given_next = given->next;
		pre = find_previous(plist, given);
		temp1 = given;
		temp2 = given_next;

		pnew1->data = given->data;
		pnew2->data = given_next->data;
		pnew2->next = pnew1;
		pnew1->next = given_next->next;

		pre->next = pnew2;
		free(given);
		free(given_next);
	}
	return;
}

//double link solution
#include <stdlib.h>
#include "linked_list.h"
void exchange_elem(llist_head* plist, int position)
{
	llist_node* previous;
	llist_node* given;
	llist_node* given_next;

	llist_node* pnew1;
	llist_node* pnew2;
	llist_node* temp1;
	llist_node* temp2;

	int i;
	//invalid position
	if (position <= 0 || position >= plist->counter)
	{
		return;
	}
	//empty head or no elem or just one elem
	if (plist == NULL || plist->next == NULL || plist->next->next == NULL)
	{
		return;
	}

	given = plist->next;
	for (i = 1; i < position; i++)
	{
		given = given->next;
	}

	pnew1 = (llist_node*)malloc(sizeof(llist_node));
	pnew2 = (llist_node*)malloc(sizeof(llist_node));
	pnew1->next = pnew2->next = NULL;

	if (position == 1)
	{
		given_next = given->next;
		temp1 = given;
		temp2 = given_next;

		pnew1->data = given->data;
		pnew1->next = given_next->next;
		pnew1->pre = pnew2;

		pnew2->data = given_next->data;
		pnew2->next = pnew1;
		pnew2->pre = NULL;
		
		plist->next = pnew2;
	}
	else
	{
		given_next = given->next;
		previous = find_previous(given);
		temp1 = given;
		temp2 = given_next;

		pnew1->data = given->data;
		pnew1->next = given_next->next;
		pnew1->pre = pnew2;

		pnew2->data = given_next->data;
		pnew2->next = pnew1;
		pnew2->pre = previous;

		pre->next = pnew2;
	}
	free(temp1);
	free(temp2);
	return;
}