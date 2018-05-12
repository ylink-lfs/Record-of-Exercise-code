#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct node
{
	int data;
	node* next;
};

struct llist
{
	node* head;
	node* rear;
	int item_count = -1;
};

void list_create(vector<int>& src, llist& body);
void list_rotate(llist&l1, llist& l2);
void list_split(llist& l1, llist& l2);
void list_terminate(llist& body);
void rotate_list_display(llist& body);

int main(void)
{
	int m, n;
	vector<int> s1;
	vector<int> s2;
	while (cin >> m)
	{
		for (int i = 0; i < m; i++)
		{
			int cache;
			cin >> cache;
			s1.push_back(cache);
		}
		llist l1;
		list_create(s1, l1);
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int cache;
			cin >> cache;
			s2.push_back(cache);
		}
		llist l2;	
		list_create(s2, l2);

		list_rotate(l1, l2);

		rotate_list_display(l1);

		list_split(l1, l2);
		list_terminate(l1);
		list_terminate(l2);

		s1.clear();
		s2.clear();
	}

	return 0;
}

void list_create(vector<int>& src, llist& body)
{
	if (body.item_count == -1)
	{
		body.head = new node;
		(body.head)->data = -10;
		(body.head)->next = nullptr;
		body.rear = nullptr;
		body.item_count++;
	}
	auto it = src.begin();
	node* current = body.head;
	while (it != src.end())
	{
		node* pnew = new node;
		pnew->data = *it;
		pnew->next = nullptr;

		current->next = pnew;
		current = current->next;
		body.rear = current;
		body.item_count++;
		it++;
	}
	return;
}

void list_rotate(llist&l1, llist& l2)
{
	l1.rear->next = l2.head->next;
	l2.rear->next = l1.head->next;
	return;
}
void list_split(llist& l1, llist& l2)
{
	l1.rear->next = nullptr;
	l2.rear->next = nullptr;
}

void list_terminate(llist& body)
{
	if (body.item_count == -1)
		return;
	else
	{
		node* current = body.head;
		node* pre = nullptr;
		while (current)
		{
			pre = current;
			current = current->next;
			delete pre;
		}
		return;
	}
}

void rotate_list_display(llist& body)
{
	if (body.item_count <= 0)
		return;
	else
	{
		node* current = body.head->next;
		bool entered = false;
		while ((int*)(current) != (int*)(body.head->next) || entered == false)
		{			
			if ((int*)(current->next) == (int*)(body.head->next) && entered == true)
			{
				cout << current->data << '\n';
			}
			else
			{
				cout << current->data << ' ';
			}
			entered = true;
			current = current->next;
		}
		return;
	}
}
