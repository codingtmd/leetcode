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
	int maxPathSum(TreeNode *root) {
		int maxAcrossRoot = INT_MIN;
		int maxEndByRoot = GetMax(root, maxAcrossRoot);
		return std::max(maxAcrossRoot, maxEndByRoot);
	}
	int GetMax(TreeNode *node, int& maxAcrossRoot)
	{
		if (node == NULL) return 0;
		int left = GetMax(node->left, maxAcrossRoot);
		int right = GetMax(node->right, maxAcrossRoot);
		int cMax = node->val;
		if (left > 0)
			cMax += left;
		if (right > 0)
			cMax += right;
		maxAcrossRoot = std::max(maxAcrossRoot, cMax);
		return std::max(
		    node->val,
		    std::max(node->val + left, node->val + right));
	}
};