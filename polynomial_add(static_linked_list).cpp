#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;

const int MAXSIZE = 20000;

//3x^5
//factor:3
//exponent:5
struct poly_term
{
	int factor;
	int exponent;
	int next;
	bool is_head;
	bool on_list;
};

struct polynomial
{
	poly_term poly[MAXSIZE];
	int head_num;
	int item_count;
};

//why declare the three variables outside main():
//1. If MAXSIZE is greater, putting them outside all the function can avoid potential stack corruption
//2. Automatically initialize all data field to 0(Useful in this program)
polynomial poly1, poly2, res;

void input_polynomial(polynomial& poly_body);
void display_polynomial(polynomial& poly_body);
polynomial add_poly(polynomial& poly1, polynomial& poly2);

int main(void)
{
	//n1 and n2 are the number of input lines for two polynomials
	int n1, n2;

	//head1 and head2 are two head node address of two static linked list
	int head1, head2;


	//meta_data input example:
	//
	//5 3
	//00010 00053
	//
	//The first polynomial has 5 input line, while the second polynomial has 3 input line
	//The first head index is 10, while the second head index is 53
	while (cin >> n1 >> n2)
	{
		cin >> head1 >> head2;

		poly1.head_num = head1;
		poly1.item_count = n1;
		input_polynomial(poly1);

		poly2.head_num = head2;
		poly2.item_count = n2;	
		input_polynomial(poly2);

		res = add_poly(poly1, poly2);
		display_polynomial(res);
	}

	return 0;
}

void input_polynomial(polynomial& poly_body)
{
	for (int i = 0; i < poly_body.item_count; i++)
	{
		//input example for one line:
		//
		//00003 3 2 00516
		//
		//current_address:00003
		//3 2 stands for 2x^3
		//next_address:00516

		int current_address, current_exp, current_fac, next_address;
		cin >> current_address >> current_exp >> current_fac >> next_address;

		poly_body.poly[current_address].exponent = current_exp;
		poly_body.poly[current_address].factor = current_fac;
		poly_body.poly[current_address].next = next_address;
		if (current_address == poly_body.head_num)
		{
			poly_body.poly[current_address].is_head = true;
		}
	}

	//exclude potential invalid input
	int item_count = 0;
	for (int i = poly_body.head_num; i != -1; i = poly_body.poly[i].next)
	{
		poly_body.poly[i].on_list = true;
		item_count++;
	}
	//this is the valid item count
	poly_body.item_count = item_count;
}

/*
polynomial operator+(polynomial poly1, polynomial poly2)
{
	polynomial res;
	for (int i = 0; i < MAXSIZE; i++)
	{
		res.poly[i].is_head = res.poly[i].on_list = false;
	}

	int index1, index2, index_res;
	index1 = poly1.head_num;
	index2 = poly2.head_num;

	index_res = 0;
	res.head_num = 0;
	res.poly[0].is_head = true;
	res.poly[0].on_list = true;

	while (index1 != -1 && index2 != -1)
	{
		if (poly1.poly[index1].exponent > poly2.poly[index2].exponent)
		{
			res.poly[index_res].factor = poly1.poly[index1].factor;
			res.poly[index_res].exponent = poly1.poly[index1].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index1 = poly1.poly[index1].next;
			index_res++;
		}
		else if (poly1.poly[index1].exponent < poly2.poly[index2].exponent)
		{
			res.poly[index_res].factor = poly2.poly[index2].factor;
			res.poly[index_res].exponent = poly2.poly[index2].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index2 = poly2.poly[index2].next;
			index_res++;
		}
		else
		{
			//factor res is 0 or not
			if (poly1.poly[index1].factor + poly2.poly[index2].factor != 0)
			{
				res.poly[index_res].exponent = poly1.poly[index1].exponent;
				res.poly[index_res].factor = poly1.poly[index1].factor + poly2.poly[index2].factor;
				res.poly[index_res].next = index_res + 1;
				res.poly[index_res].on_list = true;
				index_res++;
			}
			index1 = poly1.poly[index1].next;
			index2 = poly2.poly[index2].next;			
		}
	}

	//At here, at least one index reaches to -1
	if (index1 != -1)
	{
		while (index1 != -1)
		{
			res.poly[index_res].factor = poly1.poly[index1].factor;
			res.poly[index_res].exponent = poly1.poly[index1].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index1 = poly1.poly[index1].next;
			index_res++;
		}
	}
	if (index2 != -1)
	{
		while (index2 != -1)
		{
			res.poly[index_res].factor = poly2.poly[index2].factor;
			res.poly[index_res].exponent = poly2.poly[index2].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index2 = poly2.poly[index2].next;
			index_res++;
		}
	}
	res.item_count = index_res;
	return res;
}
*/

polynomial add_poly(polynomial& poly1, polynomial& poly2)
{
	polynomial res;
	for (int i = 0; i < MAXSIZE; i++)
	{
		res.poly[i].is_head = res.poly[i].on_list = false;
	}

	int index1, index2, index_res;
	index1 = poly1.head_num;
	index2 = poly2.head_num;

	index_res = 0;
	res.head_num = 0;
	res.poly[0].is_head = true;
	res.poly[0].on_list = true;

	while (index1 != -1 && index2 != -1)
	{
		if (poly1.poly[index1].exponent > poly2.poly[index2].exponent)
		{
			res.poly[index_res].factor = poly1.poly[index1].factor;
			res.poly[index_res].exponent = poly1.poly[index1].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index1 = poly1.poly[index1].next;
			index_res++;
		}
		else if (poly1.poly[index1].exponent < poly2.poly[index2].exponent)
		{
			res.poly[index_res].factor = poly2.poly[index2].factor;
			res.poly[index_res].exponent = poly2.poly[index2].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index2 = poly2.poly[index2].next;
			index_res++;
		}
		else
		{
			//factor res is 0 or not
			if (poly1.poly[index1].factor + poly2.poly[index2].factor != 0)
			{
				res.poly[index_res].exponent = poly1.poly[index1].exponent;
				res.poly[index_res].factor = poly1.poly[index1].factor + poly2.poly[index2].factor;
				res.poly[index_res].next = index_res + 1;
				res.poly[index_res].on_list = true;
				index_res++;
			}
			index1 = poly1.poly[index1].next;
			index2 = poly2.poly[index2].next;
		}
	}

	//At here, at least one index reaches to -1
	if (index1 != -1)
	{
		while (index1 != -1)
		{
			res.poly[index_res].factor = poly1.poly[index1].factor;
			res.poly[index_res].exponent = poly1.poly[index1].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index1 = poly1.poly[index1].next;
			index_res++;
		}
	}
	if (index2 != -1)
	{
		while (index2 != -1)
		{
			res.poly[index_res].factor = poly2.poly[index2].factor;
			res.poly[index_res].exponent = poly2.poly[index2].exponent;
			res.poly[index_res].next = index_res + 1;
			res.poly[index_res].on_list = true;
			index2 = poly2.poly[index2].next;
			index_res++;
		}
	}
	res.item_count = index_res;
	res.poly[index_res - 1].next = -1;
	return res;
}

void display_polynomial(polynomial& poly_body)
{
	int index = poly_body.head_num;
	cout << poly_body.item_count << '\n';
	while (index != -1)
	{
		cout << poly_body.poly[index].exponent;
		cout << ' ';
		cout << poly_body.poly[index].factor;
		cout << '\n';
		index = poly_body.poly[index].next;
	}
	return;
}

/*
Sample Input:
5 3
00003 00007
00008 8 3 00126
00343 1 5 02749
02749 0 4 -1
00003 10 2 00008
00126 3 1 00343
00009 3 5 11234
00007 7 3 00009
11234 0 5 -1

Sample Output:
6
10 2
8 3
7 3
3 6
1 5
9 0
*/