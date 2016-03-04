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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        int len = 1;
        ListNode* p = head, *pre;
        while (p->next != NULL)
        {
            p = p->next;
            len++;
        }
        k = len - k % len;
        p->next = head;
        int step = 0;
        while (step < k)
        {
            p = p->next;
            step++;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};