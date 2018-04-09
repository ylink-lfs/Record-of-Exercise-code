/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {

    if(root == NULL)
		;
	else if (root->val > key)
		root->left = deleteNode(root->left, key);
	else if (root->val < key)
		root->right = deleteNode(root->right, key);
	else
	{
		struct TreeNode* temp;
		struct TreeNode* min_in_right;
		if(root->left && root->right)
		{
			min_in_right = root->right;
			while(min_in_right->left)
			{
				min_in_right = min_in_right->left;
			}
			root->val = min_in_right->val;
			root->right = deleteNode(root->right, root->val);
		}
		else
		{
			if(root->left == NULL)
			{
				temp = root;
				root = root->right;
				free(temp);
			}
			else
			{
				temp = root;
				root = root->left;
				free(temp);
			}
		}
	}
	return root;

}