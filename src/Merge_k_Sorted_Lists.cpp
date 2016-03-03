/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* one = NULL;
        for (int i = 0; i < lists.size(); i++)
        {
            one = merge2Lists(one, lists[i]);
        }
        return one;
    }

    ListNode* merge2Lists(ListNode* one, ListNode* two)
    {
        if (one == NULL) return two;
        if (two == NULL) return one;
        ListNode* newHead = new ListNode(-1);
        ListNode* p = newHead;
        while (one != NULL && two != NULL)
        {
            if (one->val < two->val)
            {
                p->next = one;
                one = one->next;
            }
            else
            {
                p->next = two;
                two = two->next;
            }
            p = p->next;
        }

        if (one == NULL)
        {
            p->next = two;
        }
        else
        {
            p->next = one;
        }
        p = newHead->next;
        delete newHead;
        return p;
    }
};