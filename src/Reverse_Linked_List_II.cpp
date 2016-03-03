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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int step = n - m;
        //intro a safe guard to avoid handle head case
        ListNode* safeG = new ListNode(-1);
        safeG->next = head;
        head = safeG;
        ListNode* pre = head;
        while (m > 1)
        {
            pre = pre->next;
            m--;
        }
        ListNode* cur = pre->next, *post = cur->next;
        if (step >= 1)
        {
            // Reverse the list after m
            while (step > 0 && post != NULL)
            {
                ListNode* temp = post->next;
                post->next = cur;
                cur = post;
                post = temp;
                step--;
            }
            // link the 3 lists together
            ListNode* temp = pre->next;
            pre->next = cur;
            temp->next = post;
        }
        safeG = head;  // remove safeG
        head = head->next;
        delete safeG;
        return head;
    }
};