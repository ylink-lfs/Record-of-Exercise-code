#include "10.8a.h"

My_list::My_list()
{
	head = rear = nullptr;
	size = 0;
}

My_list::My_list(int length)
{
	if (length == 0)
	{
		head = rear = nullptr;
		size = 0;
		return;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (i == 0)
			{
				head = new node;
				rear = head;
				size = 1;
			}
			else
			{
				rear->next = new node;
				rear = rear->next;
				size++;
			}
		}
		return;
	}
}

bool My_list::isEmpty()
{
	return size ? false : true;
}

bool My_list::isFull()
{
	return size ? true : false;
}

void My_list::reset()
{
	if (size == 0)
		return;
	else if (size == 1)
	{
		delete head;
		return;
	}
	else
	{
		node* current = head;
		node* pre = nullptr;
		for (int i = 0; i < size; i++)
		{
			pre = current;
			current = current->next;
			delete pre;
		}
		return;
	}
}

void My_list::visit(void(*pf)(Item& item))
{
	if (size == 0)
		return;
	else
	{
		node* current = head;
		for (int i = 0; i < size; i++)
		{
			pf(current->item);
			current = current->next;
		}
		return;
	}
}