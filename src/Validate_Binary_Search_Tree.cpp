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
    bool isValidBST(TreeNode *root) {
        return IsValidBST(root, INT_MIN, INT_MAX);
    }
    bool IsValidBST(TreeNode* node, int MIN, int MAX)
    {
        if (node == NULL)
            return true;
        if (node->val > MIN
                && node->val < MAX
                && IsValidBST(node->left, MIN, node->val)
                && IsValidBST(node->right, node->val, MAX))
            return true;
        else
            return false;
    }
};