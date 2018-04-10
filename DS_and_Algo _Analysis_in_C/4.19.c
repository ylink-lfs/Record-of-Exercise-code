//Disgusting code. Just for pass
#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"
#include "AVLTree.h"

static AVL_node* insertion_nonrecur(AVL_node*, int);
int main(void)
{
	AVL_node* test_root = NULL;
	int i;
	AVL_node* cache = NULL;
	int min_a;
	for (i = 0; i < 5; i++)
	{
		test_root = insertion_nonrecur(test_root, i + 1);
	}
	AVL_deletion(test_root, 5);
	cache = AVL_max(test_root);
	min_a = cache->data;
	wipe_AVL(test_root);
	system("pause");
	return 0;
}

static AVL_node* insertion_nonrecur(AVL_node* root, int elem)
{
	AVL_node* current = root;
	AVL_node* pre = NULL;
	AVL_node* cache;
	AVL_node* pre_cache;
	stack_head* AVL_stack = NULL;
	int where_to = -1;
	AVL_stack = initialize_stack(AVL_stack);


	if (!current)
	{
		AVL_node* pnew = (AVL_node*)malloc(sizeof(AVL_node));
		pnew->data = elem;
		pnew->left_branch = pnew->right_branch = NULL;
		pnew->deleted = false;
		pnew->height = 0;
		root = pnew;
	}
	else
	{
		while (current && current->data != elem)
		{
			pre = current;
			push(AVL_stack, current);
			if (current->data < elem)
			{
				current = current->right_branch;
			}
			else
			{
				current = current->left_branch;
			}
		}
		if (!current)
		{
			AVL_node* pnew = (AVL_node*)malloc(sizeof(AVL_node));
			pnew->data = elem;
			pnew->left_branch = pnew->right_branch = NULL;
			pnew->deleted = false;
			pnew->height = 0;

			if (pre->data < elem)
			{
				pre->right_branch = pnew;
				pre->height = max_height(get_height(pre->left_branch), get_height(pre->right_branch)) + 1;
				if (AVL_stack->node_count >= 2)
				{
					cache = AVL_stack->rear->next->data;
					pre_cache = root;
					while (pre_cache != NULL && pre_cache->left_branch != cache && pre_cache->right_branch != cache)
					{
						if (pre_cache->data < cache->data)
						{
							pre_cache = pre_cache->right_branch;

						}
						else
						{
							pre_cache = pre_cache->left_branch;

						}
					}
					if (pre_cache != NULL && pre_cache->left_branch == cache)
					{
						where_to = 0;
					}
					else if (pre_cache != NULL && pre_cache->right_branch == cache)
					{
						where_to = 1;
					}
					if (abs_height(get_height(cache->left_branch) - get_height(cache->right_branch)) == 2)
					{
						if (cache->left_branch == pre)
						{
							cache = RL_rotation(cache);
						}
						else
						{
							cache = RR_rotation(cache);
						}
					}
					if (where_to == 1)
					{
						pre_cache->right_branch = cache;
					}
					else if (where_to == 0)
					{
						pre_cache->left_branch = cache;
					}

				}
				while (!stack_is_empty(AVL_stack))
				{
					current = pop(AVL_stack);
					current->height = max_height(get_height(current->left_branch), get_height(current->right_branch)) + 1;
					if (root->height < current->height)
					{
						root = current;
					}
				}
			}
			else
			{
				pre->left_branch = pnew;
				pre->height = max_height(get_height(pre->left_branch), get_height(pre->right_branch)) + 1;
				cache = AVL_stack->rear->next->data;
				if (AVL_stack->node_count >= 2)
				{
					cache = AVL_stack->rear->next->data;
					pre_cache = root;
					while (pre_cache != NULL && pre_cache->left_branch != cache && pre_cache->right_branch != cache)
					{
						if (pre_cache->data < cache->data)
						{
							pre_cache = pre_cache->right_branch;

						}
						else
						{
							pre_cache = pre_cache->left_branch;

						}
					}
					if (pre_cache != NULL && pre_cache->left_branch == cache)
					{
						where_to = 0;
					}
					else if (pre_cache != NULL && pre_cache->right_branch == cache)
					{
						where_to = 1;
					}
					if (abs_height(get_height(root->left_branch) - get_height(root->right_branch)) == 2)
					{
						if (cache->left_branch == pre)
						{
							cache = LL_rotation(cache);
						}
						else
						{
							cache = LR_rotation(cache);
						}
					}
					if (where_to == 1)
					{
						pre_cache->right_branch = cache;
					}
					else if (where_to == 0)
					{
						pre_cache->left_branch = cache;
					}
				}
				while (!stack_is_empty(AVL_stack))
				{
					current = pop(AVL_stack);
					current->height = max_height(get_height(current->left_branch), get_height(current->right_branch)) + 1;
					if (root->height < current->height)
					{
						root = current;
					}
				}
			}
		}
		else if (current->deleted == true)
		{
			current->deleted = false;
		}
		else
		{
			;  //element exist and isn't been deleted, do nothing
		}
	}
	wipe_stack(AVL_stack);
	return root;
}