#pragma once
struct element
{
	int data;
};

typedef element Item;

struct node
{
	Item item;
	node* next;
};


class My_list
{
private:
	node* head;
	node* rear;
	int size;
	static const int MAX_SIZE = 1000;
public:
	My_list();
	My_list(int length);
	void reset();
	void traverse(void(*pf)(Item& item));
	bool isEmpty();
	bool isFull();
};