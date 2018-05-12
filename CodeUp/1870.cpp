#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

struct Item
{
	int id;
	int score;
};

struct node
{
	Item item;
	node* next;
};

struct llist
{
	node* head;
	int item_count = -1;
};

void list_create(vector<Item>& src, llist& body);
void list_sort(llist& body);
void swap(Item& i1, Item& i2);
void list_terminate(llist& body);
void list_display(llist& body);

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<Item> cache_input;
	int m, n;

	while (cin >> m >> n)
	{
		n += m;
		for (int i = 0; i < n; i++)
		{
			Item cache;
			cin >> cache.id >> cache.score;
			cache_input.push_back(cache);
		}
		llist op_list;
		list_create(cache_input, op_list);
		list_sort(op_list);
		list_display(op_list);
		list_terminate(op_list);
		cache_input.clear();
	}

	return 0;
}

void list_create(vector<Item>& src, llist& body)
{
	if (body.item_count == -1)
	{
		body.head = new node;
		(body.head)->item.id = (body.head)->item.score = -10;
		(body.head)->next = nullptr;
		body.item_count++;
	}
	auto it = src.begin();
	node* current = body.head;
	while (it != src.end())
	{
		Item cache;
		cache.id = (*it).id;
		cache.score = (*it).score;

		node* pnew = new node;
		pnew->item = cache;
		pnew->next = nullptr;

		current->next = pnew;
		current = current->next;
		body.item_count++;
		it++;
	}
	return;
}

void list_sort(llist& body)
{
	if (body.item_count <= 1)
		return;
	else
	{
		node* current = body.head->next;
		node* sub = nullptr;
		while (current->next)
		{
			sub = current->next;
			while (sub)
			{
				if (current->item.id > sub->item.id)
				{
					swap(current->item, sub->item);
				}
				sub = sub->next;
			}
			current = current->next;
		}
		return;
	}
}

void swap(Item& i1, Item& i2)
{
	int temp;

	temp = i1.id;
	i1.id = i2.id;
	i2.id = temp;

	temp = i1.score;
	i1.score = i2.score;
	i2.score = temp;

	return;
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

void list_display(llist& body)
{
	if (body.item_count <= 0)
		return;
	else
	{
		node* current = body.head->next;
		while (current)
		{
			cout << current->item.id << ' ' << current->item.score << '\n';
			current = current->next;
		}
		return;
	}
}
