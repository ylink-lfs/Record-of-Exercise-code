//This program gets specific Huffman code for a string which contains only alphabetical characters
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

struct tree_node
{
	char data;
	int current_val;
	tree_node* left_branch;
	tree_node* right_branch;
};

struct queue_cmp
{
	bool operator()(tree_node* node1, tree_node* node2)
	{
		return node1->current_val > node2->current_val;
	}
};

tree_node* build_huffman_code_tree(priority_queue<tree_node*, vector<tree_node*>, queue_cmp>& src);

void get_huffman_code(tree_node* root, vector<char>& board, vector<pair<char, vector<char>>>& res);

void wipe_huffman_tree(tree_node* root);

bool cmp(pair<char, vector<char>>& p1, pair<char, vector<char>>& p2);

int main(void)
{
	string input_str;
	
	cout << "Please input string for huffman coding";
	cout << " (The program will automatically wipe non-alphabetical input) :\n";
	while (getline(cin, input_str))
	{
		unordered_map<char, int> char_count;
		for (int i = 0; i < input_str.size(); i++)
		{
			if (!isalpha(input_str[i]))
			{
				input_str.erase(i, 1);
				i--;
			}
			else
			{
				if (char_count.find(input_str[i]) != char_count.end())
				{
					char_count[input_str[i]]++;
				}
				else
				{
					char_count.insert(make_pair(input_str[i], 1));
				}
			}
		}
		if (input_str.size() == 0)
		{
			cout << "No valid alphabetical character left. Please input string again.";
			cout << "Enter Ctrl + Z for program termination.\n";
			continue;
		}
		else
		{
			priority_queue<tree_node*, vector<tree_node*>, queue_cmp> src;
			for (auto it = char_count.begin(); it != char_count.end(); it++)
			{
				tree_node* cache = new tree_node;
				cache->data = it->first;
				cache->current_val = it->second;
				cache->left_branch = cache->right_branch = nullptr;
				src.push(cache);
			}	
			tree_node* root = build_huffman_code_tree(src);

			vector<char> board;
			vector<pair<char, vector<char>>> code_res;
			get_huffman_code(root, board, code_res);
			sort(code_res.begin(), code_res.end(), cmp);

			cout << "Huffman Code for given string:\n";
			for (auto it = code_res.begin(); it < code_res.end(); it++)
			{
				cout << it - code_res.begin() + 1 << ". " << it->first << ": ";
				for (auto sub_it = it->second.begin(); sub_it < it->second.end(); sub_it++)
				{
					cout << *sub_it;
				}
				cout << endl;
			}
			cout << "The translation result is: ";
			for (int i = 0; i < input_str.size(); i++)
			{
				auto it = code_res.begin();
				for (; it < code_res.end(); it++)
				{
					//Result must exist
					if (it->first == input_str[i])
						break;
				}
				for (auto sub_it = it->second.begin(); sub_it < it->second.end(); sub_it++)
				{
					cout << *sub_it;
				}
			}
			wipe_huffman_tree(root);

			cout << endl;
			cout << endl;
			cout << "Next input please (Enter Ctrl + Z for program termination) :\n";
			continue;
		}
	}
	cout << "Program catches End Of Input.\nBye!\n";

	return 0;
}

tree_node* build_huffman_code_tree(priority_queue<tree_node*, vector<tree_node*>, queue_cmp>& src)
{
	tree_node* father = src.top();
	while (src.size() > 1)
	{
		tree_node* lchild = src.top();
		src.pop();
		tree_node* rchild = src.top();
		src.pop();
		tree_node* cache = new tree_node;

		cache->data = '#';
		cache->current_val = lchild->current_val + rchild->current_val;
		cache->left_branch = lchild;
		cache->right_branch = rchild;

		src.push(cache);
	}
	father = src.top();
	src.pop();
	if (father->left_branch)
	{
		father->current_val = father->left_branch->current_val + father->right_branch->current_val;
	}
	return father;
}

void get_huffman_code(tree_node* root, vector<char>& board, vector<pair<char, vector<char>>>& res)
{
	if (isalpha(root->data))
	{
		res.push_back(make_pair(root->data, board));
		return;
	}
	else
	{
		board.push_back('0');
		get_huffman_code(root->left_branch, board, res);
		board.pop_back();
		board.push_back('1');
		get_huffman_code(root->right_branch, board, res);
		board.pop_back();
		return;
	}
}

void wipe_huffman_tree(tree_node* root)
{
	if (root == nullptr)
		return;
	wipe_huffman_tree(root->left_branch);
	wipe_huffman_tree(root->right_branch);
	delete root;
	return;
}

bool cmp(pair<char, vector<char>>& p1, pair<char, vector<char>>& p2)
{
	return p1.first < p2.first;
}