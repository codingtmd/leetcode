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
	ListNode *sortList(ListNode *head) {
		// Get length first
		ListNode* p = head;
		int len = 0;
		while (p != NULL)
		{
			p = p->next;
			len++;
		}

		ListNode* fakehead = new ListNode(-1);
		fakehead->next = head;

		for (int interval = 1; interval <= len; interval = interval * 2)
		{
			ListNode* pre  = fakehead;
			ListNode* slow = fakehead->next, *fast = fakehead->next;
			while (fast != NULL || slow != NULL)
			{
				int i = 0;
				while (i < interval && fast != NULL)
				{
					fast = fast->next; //move fast pointer ahead for interval steps
					i++;
				}

				//merge two lists, which has only interval length
				int fvisit = 0, svisit = 0;
				while (fvisit < interval && svisit < interval && fast != NULL && slow != NULL)
				{
					if (fast->val < slow->val)
					{
						pre->next = fast;
						pre = fast;
						fast = fast->next;
						fvisit++;
					}
					else
					{
						pre->next = slow;
						pre = slow;
						slow = slow->next;
						svisit++;

					}
				}

				while (fvisit < interval && fast != NULL)
				{
					pre->next = fast;
					pre = fast;
					fast = fast->next;
					fvisit++;
				}

				while (svisit < interval && slow != NULL)
				{
					pre->next = slow;
					pre = slow;
					slow = slow->next;
					svisit++;
				}
				pre->next = fast;
				slow = fast;

			}


		}

		ListNode* newhead = fakehead->next;
		delete fakehead;
		return newhead;
	}
};