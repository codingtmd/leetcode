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
    ListNode *detectCycle(ListNode *head) {

        ListNode * first = head;
        ListNode * second = head;

        while (first != NULL && second != NULL)
        {
            first = first->next;
            second = second->next;
            if (second != NULL)
                second = second->next;
            if (first == second)
                break;
        }

        if (second == NULL) return NULL;

        // 一起往下走X步，就找到节点了。
        first = head;
        while (first != second)
        {
            first = first->next;
            second = second->next;
        }

        return second;
    }
};