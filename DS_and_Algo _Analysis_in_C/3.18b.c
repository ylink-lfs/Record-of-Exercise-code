#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linked_stack.h"

int main(void)
{
	char read_line[200];
	char read_cache[3];
	char* comment_address = NULL;
	symbol_item checking;
	bool unmatch = false;
	unsigned int i;
	int line_count = 1;

	stack_head* check_head = NULL;
	check_head = initialize_stack(check_head);
	while (fgets(read_line, 200, stdin) != NULL)
	{
		for (i = 0; i < strlen(read_line); i++)
		{			
			if (i + 2 <= strlen(read_line))
			{
				read_cache[0] = read_line[i];
				read_cache[1] = read_line[i + 1];
				read_cache[2] = '\0';
			}
			if (read_line[i] == '(' || read_line[i] == '[' || read_line[i] == '{')
			{
				checking.single = read_line[i];
				push(check_head, checking);
			}
			else if (read_line[i] == ')' || read_line[i] == ']' || read_line[i] == '}')
			{
				checking = stack_top_item(check_head);
				if (read_line[i] == ')')
				{
					if (checking.single == '(')
					{
						pop(check_head);
					}
					else
					{
						unmatch = true;
						fprintf(stderr, "Bracket unmatch occur in line %d, character %d\n", line_count, i);
						wipe_stack(check_head);
						system("pause");
						exit(EXIT_SUCCESS);
					}
				}
				else if (read_line[i] == ']')
				{
					if (checking.single == '[')
					{
						pop(check_head);
					}
					else
					{
						unmatch = true;
						fprintf(stderr, "Bracket unmatch occur in line %d, character %d\n", line_count, i);
						wipe_stack(check_head);
						system("pause");
						exit(EXIT_SUCCESS);
					}
				}
				else
				{
					if (checking.single == '{')
					{
						pop(check_head);
					}
					else
					{
						unmatch = true;
						fprintf(stderr, "Bracket unmatch occur in line %d, character %d\n", line_count, i);
						wipe_stack(check_head);
						system("pause");
						exit(EXIT_SUCCESS);
					}
				}
			}
			else if (!strcmp(read_cache, "/*"))
			{
				strcpy(checking.multiple, read_cache);
				push(check_head, checking);
			}

			//don't know how to deal with the case '*' and '/' don't in one line
			//wait for search
			else if (!strcmp(read_cache, "*/"))  
			{
				if (strcmp("/*", stack_top_item(check_head).multiple))
				{
					unmatch = true;
					fprintf(stderr, "Comment symbol unmatch occur in line %d, character %d\n", line_count, i);
					wipe_stack(check_head);
					system("pause");
					exit(EXIT_SUCCESS);
				}
				else
				{
					pop(check_head);
				}
			}
			else
			{
				;
			}
			
		}
		line_count++;
	}
	if (stack_is_empty(check_head) && unmatch == false)
	{
		printf("All match\n");
	}
	else
	{
		printf("%d characters unmatch\n", stack_length(check_head));
	}
	wipe_stack(check_head);
	system("pause");
	return 0;
}