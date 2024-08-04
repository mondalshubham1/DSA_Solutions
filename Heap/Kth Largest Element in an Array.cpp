// Problem Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;              // A min heap that will store k elements
        for(auto x: nums) {
            if(pq.size()<k)                     // if there are less than k elements, I'll enter the new element
                pq.push(x);

            else{
                if(pq.top()<x)                 // if the new element is greater than the top element of min heap, then the top element can never be the kth largest element.
                {
                    pq.pop();
                    pq.push(x);
                }
  // else if the new element is smaller than the top element of min heap, then it never can be the kth largest element as we already have k elements greater than that new element.
            }
        }
        return pq.top();
    }
};
