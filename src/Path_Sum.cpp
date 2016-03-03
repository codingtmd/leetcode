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
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSum(root, 0, sum);
    }
    bool hasPathSum(TreeNode *root, int sum, int target) {
        if (root == NULL) return false;
        sum += root->val;
        if (root->left == NULL && root->right == NULL) //leaf
        {
            if (sum == target)
                return true;
            else
                return false;
        }
        return hasPathSum(root->left, sum, target)
               || hasPathSum(root->right, sum, target);
    }
};