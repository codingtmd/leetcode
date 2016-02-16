/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		//insert nodes
		RandomListNode * cur = head;
		while (cur != NULL)
		{
			RandomListNode* temp = new RandomListNode(cur->label);
			temp->next = cur->next;
			cur->next = temp;
			cur = temp->next;
		}
		// copy random pointer
		cur = head;
		while (cur != NULL)
		{
			RandomListNode* temp = cur->next;
			if (cur->random != NULL)
				temp->random = cur->random->next;
			cur = temp->next;
		}
		//decouple two links
		cur = head;
		RandomListNode* dup = head == NULL ? NULL : head->next;
		while (cur != NULL)
		{
			RandomListNode* temp = cur->next;
			cur->next = temp->next;
			if (temp->next != NULL)
				temp->next = temp->next->next;
			cur = cur->next;
		}
		return dup;
	}
};