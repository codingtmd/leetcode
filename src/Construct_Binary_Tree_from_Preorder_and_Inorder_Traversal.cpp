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
	TreeNode *buildTree(
	    vector<int> &preorder,
	    vector<int> &inorder)
	{
		return BuildTreePI( preorder, inorder,
		                    0, preorder.size() - 1, 0, preorder.size());
	}
	TreeNode* BuildTreePI(
	    vector<int> &preorder,
	    vector<int> &inorder,
	    int p_s, int p_e,
	    int i_s, int i_e)
	{
		if (p_s > p_e)
			return NULL;
		int pivot = preorder[i_s];
		int i = p_s;
		for (; i < p_e; i++)
		{
			if (inorder[i] == pivot)
				break;
		}
		TreeNode* node = new TreeNode(pivot);
		node->left = BuildTreePI(preorder, inorder,
		                         p_s, i - 1, i_s + 1, i - p_s + i_s);
		node->right = BuildTreePI(preorder, inorder,
		                          i + 1, p_e, i - p_s + i_s + 1, i_e);
		return node;
	}
};