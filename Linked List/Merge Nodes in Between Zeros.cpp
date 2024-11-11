// Problem Link : https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tmp1;              // this pointer will stay at 0 node
        ListNode* tmp2;              // this pointer will move forward to add up the nodes
        tmp1=head;
        tmp2=head->next;
        int sum = 0;
        while(tmp2 != NULL) {
            if(tmp2->val != 0) {
                sum += tmp2->val;
                ListNode* prev = tmp2;
                tmp2 = tmp2->next;
                delete prev;
            }
            else {
                tmp1->val = sum;
                if(tmp2->next == NULL){
                    tmp1->next = NULL;
                    delete tmp2;
                    break;
                }   
                tmp1->next = tmp2;
                sum = 0;

                tmp1 = tmp2;
                tmp2 = tmp1->next;
            }
        }
        return head;   
    }
};
