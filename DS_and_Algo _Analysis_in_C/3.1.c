#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main(void)
{
	llist_head* print_list = NULL;
	llist_node* current;
	int i;
	int times;
	char check;
	srand(time(NULL));
	print_list = initialize_llist(print_list);
	printf("This program prints list items. Input q to exit this program.\n");
	printf("Wait for input:");
	while (scanf("%c", &check) == 1 && check != 'q')
	{
		getchar();
		times = rand();
		for (i = 1; i <= times; i++)
		{
			llist_insertion(print_list, rand(), i);
		}
		if (print_list->next != NULL)
		{
			current = print_list->next;
		}
		for (i = 1; i <= times; i++)
		{
			printf("%d ", current->data);
			current = current->next;
		}
		initialize_llist(print_list);
		printf("\nNext control character plz(Enter q to quit):\n");
		printf("Wait for input:");
	}
	wipe_llist(print_list);
	system("pause");
	return 0;
}