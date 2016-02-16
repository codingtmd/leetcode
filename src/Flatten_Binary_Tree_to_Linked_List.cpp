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
	TreeNode *lastVisitedNode = NULL;
	void flatten(TreeNode *root) {
		if (root == NULL) return;

		TreeNode* right = root->right;
		if (lastVisitedNode != NULL)
		{
			lastVisitedNode->left = NULL;
			lastVisitedNode->right = root;
		}
		lastVisitedNode = root;
		flatten(root->left);
		flatten(right);
	}
};