/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode*> tStack;
		vector<int> result;
		while (tStack.size() > 0 || root != NULL)
		{
			if (root != NULL)
			{
				result.push_back(root->val);
				if (root->right != NULL)
					tStack.push(root->right);
				root = root->left;
			}
			else
			{
				root = tStack.top();
				tStack.pop();
			}
		}
		return result;
	}

};