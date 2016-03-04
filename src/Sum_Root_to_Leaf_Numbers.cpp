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
    int total;
    int sumNumbers(TreeNode *root) {
        total = 0;
        sumPath(root, 0);
        return total;
    }

    void sumPath(TreeNode* node, int pathSum)
    {
        if (node == NULL) return;
        int newSum = pathSum * 10 + node->val;
        if (node->left == NULL && node->right == NULL)
        {
            total += newSum;
            return;
        }

        sumPath(node->left, newSum);

        sumPath(node->right, newSum);
    }
};