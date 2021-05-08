// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/

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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
		    return a->val > b->val;
	    }   
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int k = lists.size();
        if (!k)
            return 0;

        for (int i = 0; i < k; i++) {
            if (lists[i])
        	    pq.push(lists[i]);
        }

        ListNode* resHead = new ListNode(0);
        ListNode* last = resHead;

        while (!pq.empty()) {
        	ListNode* curr = pq.top();
        	pq.pop();

        	last->next = curr;
        	last = last->next;

        	if (curr->next)
        		pq.push(curr->next);
        }
        return resHead->next;
    }
};
