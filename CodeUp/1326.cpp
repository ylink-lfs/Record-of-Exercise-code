#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>

using std::cin;
using std::cout;
using std::string;

struct node
{
	node* next;
	int data;
};

struct llist
{
	node* head;
	int item_count = -1;
};

void list_get(llist& listbody, int pos);
void list_delete(llist& listbody, int pos);
void list_insert(llist& listbody, int pos, int elem);
void list_show(llist& listbody);
void list_create(llist& listbody, int* src, int count);
void list_terminate(llist& listbody);

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int elem_count;
	llist operate_list;

	cin >> elem_count;
	int* arr = new int[elem_count];
	for (int i = 0; i < elem_count; i++)
	{
		cin >> arr[i];
	}
	list_create(operate_list, arr, elem_count);
	delete[]arr;

	string str_cache;
	int num_cache1;
	int num_cache2;
	int line_count;
	int switcher;
	cin >> line_count;

	for (int i = 0; i < line_count; i++)
	{
		cin >> str_cache;
		if (str_cache == "get")
			switcher = 1;
		else if (str_cache == "insert")
			switcher = 2;
		else if (str_cache == "delete")
			switcher = 3;
		else
			switcher = 4;
		switch (switcher)
		{
		case 1: cin >> num_cache1; list_get(operate_list, num_cache1); break;
		case 2: cin >> num_cache1 >> num_cache2; list_insert(operate_list, num_cache1, num_cache2); break;
		case 3: cin >> num_cache1; list_delete(operate_list, num_cache1); break;
		case 4: list_show(operate_list); break;
		}
	}
	return 0;
}

void list_get(llist& listbody, int pos)
{
	if (pos <= 0 || pos > listbody.item_count)
	{
		cout << "get fail\n";
		return;
	}
	else
	{
		node* current = listbody.head;
		for (int i = 0; i < pos; i++)
		{
			current = current->next;
		}
		cout << current->data << '\n';
		return;
	}
}

void list_delete(llist& listbody, int pos)
{
	if (pos <= 0 || pos > listbody.item_count)
	{
		cout << "delete fail\n";
		return;
	}
	else
	{
		node* current = listbody.head;
		node* pre = nullptr;
		for (int i = 0; i < pos; i++)
		{
			pre = current;
			current = current->next;
		}
		pre->next = current->next;
		delete current;
		listbody.item_count--;
		cout << "delete OK\n";
		return;
	}
}

void list_insert(llist& listbody, int pos, int elem)
{
	if (pos <= 0 || pos > listbody.item_count + 1)
	{
		cout << "insert fail\n";
		return;
	}
	else
	{
		node* current = listbody.head;
		node* pre = nullptr;
		for (int i = 0; i < pos; i++)
		{
			pre = current;
			current = current->next;
		}
		node* pnew = new node;
		pnew->data = elem;
		pnew->next = current;
		pre->next = pnew;
		listbody.item_count++;
		cout << "insert OK\n";
		return;
	}
}

void list_show(llist& listbody)
{
	if (listbody.item_count <= 0)
	{
		cout << "Link list is empty\n";
		return;
	}
	else
	{
		node* current = listbody.head->next;
		while (current)
		{
			if (current->next)
			{
				cout << current->data << ' ';
			}
			else
			{
				cout << current->data << '\n';
			}
			current = current->next;
		}
		return;
	}
}

void list_create(llist& listbody, int* src, int count)
{
	if (listbody.item_count == -1)
	{
		node* new_head = new node;
		new_head->data = INT_MIN;
		new_head->next = nullptr;
		listbody.head = new_head;
		listbody.item_count++;
	}
	node* current = listbody.head;
	for (int i = 0; i < count; i++)
	{
		node* pnew = new node;
		pnew->data = src[i];
		pnew->next = current->next;
		current->next = pnew;
		listbody.item_count++;
	}
	return;
}

void list_terminate(llist& listbody)
{
	if (listbody.item_count == -1)
		return;
	else
	{
		node* current = listbody.head;
		node* pre = nullptr;
		while (current)
		{
			pre = current;
			current = current->next;
			delete pre;
			listbody.item_count--;
		}
		return;
	}
}
