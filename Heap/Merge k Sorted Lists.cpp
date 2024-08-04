// Problem link : https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;      // Maintain a min heap containing the k elements, the minimum out of them will be the next element in the result LinkedList.
        for(int i=0; i<lists.size(); i++) {           // Push the head of all the given linked lists initially in the priority queue.
            if(lists[i]!=NULL)
                pq.push(make_pair(-1*(lists[i]->val), lists[i]));
        }

        ListNode* ans_head = NULL;
        ListNode* ans_back = NULL;

        while(!pq.empty()) {
            pair<int, ListNode*> min_val = pq.top();
            pq.pop();

            if(ans_head == NULL) {                       // for the very first node in the result LinkedList
                ans_head = min_val.second;
                ans_back = ans_head;
            }
            else {                                      
                ans_back->next = min_val.second;
                ans_back = ans_back->next;
            }

            ListNode* next_element_of_min_val = (min_val.second)->next;
            if(next_element_of_min_val != NULL)
            {
                pq.push(make_pair(-1*(next_element_of_min_val->val), next_element_of_min_val));
            }   
        }

        return ans_head;
    }
};
