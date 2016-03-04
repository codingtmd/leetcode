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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* safeG = new ListNode(-1);
        safeG->next = head; // head will be changed in next switch
        ListNode *pre = head->next;
        ListNode *cur = head;
        ListNode *post = safeG;
        while (pre != NULL)
        {
            ListNode* temp = pre->next;
            pre->next = cur;
            cur->next = temp;
            post->next = pre;
            post = cur;
            if (post->next == NULL) break;
            cur = post->next;
            pre = cur->next;
        }
        head = safeG->next;
        delete safeG;
        return head;
    }
};