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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* pre, *cur;
        pre = head; cur = head;
        int step = 0;
        while (step < n && cur != NULL)
        {
            cur = cur->next;
            step++;
        }
        if (step == n && cur == NULL)
        {
            head = head->next;
            delete pre;
            return head;
        }
        while (cur->next != NULL)
        {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* temp = pre->next;
        pre->next = temp->next;
        delete temp;
        return head;
    }
};