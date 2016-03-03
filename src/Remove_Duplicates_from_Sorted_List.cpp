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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode * pre = head;
        ListNode *p = head->next;
        while (p != NULL)
        {
            if (pre->val == p->val)
            {
                ListNode* temp = p;
                p = p->next;
                pre->next = p;
                // need delete the unused node. Or memory leak
                delete temp;
                continue;
            }
            pre = pre->next;
            p = p->next;
        }
        return head;
    }
};