#include <stdlib.h>
#include "sequential_self_adjusting_list.h"

self_a_list* create_that_list(self_a_list* psalist)
{
	psalist = (self_a_list*)malloc(sizeof(self_a_list));
	psalist->item_count = 0;
	return psalist;
}

void ask(self_a_list* psalist, ElementType elem)
{
	int elem_index = search_elem(psalist, elem);
	int elem_cache;
	int i;
	if (elem_index == 0)
	{
		return;
	}
	else
	{
		elem_cache = psalist->data[elem_index];
		for (i = elem_index - 1; i >= 1; i--)
		{
			psalist->data[i + 1] = psalist->data[i];
		}
		psalist->data[1] = elem_cache;
		return;
	}
}