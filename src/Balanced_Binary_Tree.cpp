/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (root == NULL) return true;
		int val = GetBalance(root);
		if (val == -1) return false;
		return true;
	}
	int GetBalance(TreeNode* node)
	{
		if (node == NULL)
			return 0;
		int left = GetBalance(node->left);
		if (left == -1) return -1;
		int right = GetBalance(node->right);
		if (right == -1) return -1;
		if (left - right > 1 || right - left > 1)
			return -1;
		return left > right ? left + 1 : right + 1;
	}

};