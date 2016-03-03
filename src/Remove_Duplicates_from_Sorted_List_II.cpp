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
        ListNode* dummy =  new ListNode(INT_MIN);
        dummy->next = head;

        ListNode* pre = dummy, *cur = head;
        while (cur != NULL)
        {
            ListNode* post = cur->next;
            bool isDup = false;
            while (post != NULL && cur->val == post->val)
            {
                delete cur;
                cur = post;
                post = cur->next;
                isDup = true;
            }

            if (isDup)
            {
                ListNode* temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }

            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};