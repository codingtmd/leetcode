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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        vector<int> nodes;
        getAllPaths(root, nodes, paths);          
        return paths;
    }
    
    void getAllPaths(TreeNode* node, vector<int>& nodes,vector<string>& paths) {
        if(node == NULL) {
            return;
        }
        if(node->left== NULL && node->right == NULL) {
            stringstream ss;
            for(int i =0; i< nodes.size(); i++) {
                ss << nodes[i] << "->";
            }
            ss << node->val;
            paths.push_back(ss.str());
            return;
        }
        
        nodes.push_back(node->val);
        getAllPaths(node->left, nodes, paths);
        getAllPaths(node->right, nodes, paths);
        nodes.pop_back();
    }
};