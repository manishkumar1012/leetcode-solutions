/* Problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
  Idea: The late pointer needs to be on the node before the node to be deleted, so move the early pointer n nodes ahead.
  And handle the case of deleting the first node with care.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *late = head, *early = head;
        for (int i = 0; i < n; i++) {
        	if (!early->next) {
        		ListNode *temp = head;
        		head = head->next;
        		delete temp;
        		return head;
        	}
        	early = early->next;
        }

        while (early->next) {
        	early = early->next;
        	late = late->next;
        }

        ListNode *temp = late->next;
        late->next = temp->next;
        delete temp;
        return head;
    }
};
