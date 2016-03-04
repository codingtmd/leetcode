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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* safeG = new ListNode(-1);
        safeG->next = head;
        if (head == NULL || k == 1) return head;
        ListNode* pre = safeG, *cur = head, *post = head->next;
        while (cur != NULL)
        {
            post = cur->next;
            int i = 0;
            while (i < k - 1 && post != NULL)
            {
                ListNode *temp = post->next;
                post->next = cur;
                cur = post;
                post = temp;
                i++;
            }
            if (i != k - 1)
            {
                int k = 0;
                ListNode * temp = post;
                post = cur;
                cur = temp;
                while (k < i)
                {
                    temp = post->next;
                    post->next = cur;
                    cur = post;
                    post = temp;
                    k++;
                }
                break;
            }
            ListNode* temp = pre->next;
            pre->next = cur;
            temp->next = post;
            pre = temp;
            cur = pre->next;
        }
        head = safeG->next;
        delete safeG;
        return head;
    }
};