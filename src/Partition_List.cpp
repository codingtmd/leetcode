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

    ListNode *partition(ListNode *head, int x) {
        ListNode* p = new ListNode(x - 1);
        p->next = head;
        head = p;
        ListNode* pre;
        while (p != NULL && p->val < x)
        {
            pre = p;
            p = p->next;
        }
        if (p != NULL)
        {
            //Track the insert position.
            ListNode* cur = pre;
            while (p != NULL)
            {
                if (p->val < x)
                {
                    ListNode* temp = cur->next;
                    pre->next = p->next;
                    cur->next = p;
                    cur = p;
                    p->next = temp;
                    p = pre;
                }
                pre = p;
                p = p->next;
            }
        }
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};