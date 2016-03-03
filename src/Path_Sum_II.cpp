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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > collect;
        vector<int> solution;
        if (root != NULL)
            GetPath(root, sum, 0, solution, collect);
        return collect;
    }
    void GetPath(TreeNode* node, int sum, int cal, vector<int>& solution, vector<vector<int> >& collect)
    {
        solution.push_back(node->val);
        cal += node->val;
        if (cal == sum && node->left == NULL && node->right == NULL)
        {
            collect.push_back(solution);
        }
        else
        {
            if (node->left != NULL)
            {
                GetPath(node->left, sum, cal, solution, collect);
            }
            if (node->right != NULL)
            {
                GetPath(node->right, sum, cal, solution, collect);
            }
        }
        solution.pop_back();

        return;
    }
};