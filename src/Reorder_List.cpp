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
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        // find the median node
        ListNode* fast = head;
        ListNode* slow = head;
        while (true)
        {
            fast = fast->next;
            if (fast == NULL)
                break;
            fast = fast->next;
            if (fast == NULL)
                break;
            slow = slow->next;
        }

        if (slow == NULL) return;

        // reverse second half of link list
        ListNode* cur = slow;
        ListNode* pre = slow->next;
        cur->next = NULL;
        while (pre != NULL)
        {
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }

        // merge two lists
        ListNode* first = head;
        ListNode* second = cur;

        while (second != NULL && first != NULL && first != second)
        {
            ListNode* temp = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = temp;
        }
    }
};