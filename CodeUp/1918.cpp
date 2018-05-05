#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stack>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::map;
using std::stack;

union elem
{
	double num;
	char opt;
};

struct element
{
	bool isDigit;
	elem item;
};

double str_t_num(string& str, string::iterator& pos);

element container[200];
element postfix_exp[200];

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string str_cache;
	map<char, int> priority;

	priority['+'] = priority['-'] = 1;
	priority['*'] = priority['/'] = 2;

	int container_index;  //container_index represents actual element nums
	while (getline(cin, str_cache))
	{		
		if (str_cache.size() == 1 && str_cache[0] == '0')
			break;
		container_index = 0;
		auto main_it = str_cache.begin();
		while (main_it != str_cache.end())
		{
			if (ispunct(*main_it))
			{
				container[container_index].isDigit = false;
				container[container_index].item.opt = *main_it;
				container_index++;
				main_it++;
			}
			else if (isdigit(*main_it))
			{
				double cache = str_t_num(str_cache, main_it);
				container[container_index].isDigit = true;
				container[container_index].item.num = cache;
				container_index++;
			}
			else
				main_it++;
		}
		stack<char> opt_contain;
		int traverse_inorder_fix = 0;
		int traverse_postfix = 0;
		while (traverse_inorder_fix < container_index)
		{
			if (container[traverse_inorder_fix].isDigit == true)
			{
				postfix_exp[traverse_postfix].isDigit = true;
				postfix_exp[traverse_postfix].item.num = container[traverse_inorder_fix].item.num;
				traverse_inorder_fix++;
				traverse_postfix++;
				continue;
			}
			else
			{
				char cache = container[traverse_inorder_fix].item.opt;
				if (opt_contain.empty() || priority[cache] > priority[opt_contain.top()])
				{
					opt_contain.push(cache);
					traverse_inorder_fix++;
					continue;
				}
				else
				{
					while (!opt_contain.empty() && priority[opt_contain.top()] >= priority[cache])
					{
						char receiver = opt_contain.top();
						opt_contain.pop();
						postfix_exp[traverse_postfix].isDigit = false;
						postfix_exp[traverse_postfix].item.opt = receiver;
						traverse_postfix++;
					}
					opt_contain.push(cache);
					traverse_inorder_fix++;
					continue;
				}
			}
		}
		while (!opt_contain.empty())
		{
			postfix_exp[traverse_postfix].isDigit = false;
			postfix_exp[traverse_postfix].item.opt = opt_contain.top();
			opt_contain.pop();
			traverse_postfix++;
		}

		stack<double> num_container;
		int i = 0;
		while (i < traverse_postfix)
		{
			if (postfix_exp[i].isDigit == true)
			{
				num_container.push(postfix_exp[i].item.num);
				i++;
				continue;
			}
			else
			{
				double first_pop = num_container.top();
				num_container.pop();
				double second_pop = num_container.top();
				num_container.pop();
				double res;

				char opt_cache = postfix_exp[i].item.opt;
				switch (opt_cache)
				{
				case '+':res = second_pop + first_pop; break;
				case '-':res = second_pop - first_pop; break;
				case '*':res = second_pop * first_pop; break;
				case '/':res = second_pop / first_pop; break;
				}
				num_container.push(res);
				i++;
				continue;
			}
		}
		double output_res = num_container.top();
		cout.setf(std::ios_base::fixed);
		cout.precision(2);
		cout << output_res << '\n';
	}
	return 0;
}

double str_t_num(string& str, string::iterator& pos)
{
	auto sub_it = pos + 1;
	while (sub_it < str.end() && isdigit(*sub_it))
		sub_it++;
	int length = sub_it - pos;
	int times = int(pow(10, length - 1));
	int cache = 0;
	while (pos != sub_it)
	{
		cache += times * (*pos - 48);
		times /= 10;
		pos++;
	}
	return double(cache);
}
