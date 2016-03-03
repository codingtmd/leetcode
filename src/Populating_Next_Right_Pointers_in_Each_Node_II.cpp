/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* cur = root, *next = NULL;
        while (cur != NULL)
        {
            TreeLinkNode *p = cur, *k = NULL;
            while (p != NULL)
            {
                TreeLinkNode* sub = getLinkedLeftNode(p);
                if (sub != NULL)
                {
                    if (next == NULL)
                    {
                        next = sub;
                        k = sub;
                    }
                    else
                        k->next = sub;
                    while (k->next != NULL) // ietrate to the tail
                        k = k->next;
                }
                p = p->next;
            }
            cur = next;
            next = NULL;
        }
    }

    TreeLinkNode* getLinkedLeftNode(TreeLinkNode * root)
    {
        if (root->left != NULL && root->right != NULL)
            root->left->next = root->right;
        if (root->left != NULL)
            return root->left;
        if (root->right != NULL)
            return root->right;
        return NULL;
    }
};