// Problem Link : https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0; i<k; i++) {                                          // Maintain a monotonically decreasing queue, the front element will have the maximum element in that window.
            while(!dq.empty() && dq.back()<nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);                   // Trying to create a deque for the first subarray of size k. 
        }

        // Slide the window
        vector<int> ans;
        for(int i=0; i+k<nums.size() ; i++) {
            ans.push_back(dq.front());                                   // Front element is the maximum in the previous window.

            int pop_element = nums[i];                            // In the next window, ith element will be thrown out of the window and i+kth element will be added in the deque.
            int push_element = nums[i+k];    

            // Here we throw the element out of the deque that can never be the maximum of any sliding window, hence we maintain a monotonically decreasing deque.
          
            if(dq.front() == pop_element) {
                dq.pop_front();
            }

            while(!dq.empty() && dq.back()<push_element) {
                dq.pop_back();
            }    
            dq.push_back(push_element);
        }

        ans.push_back(dq.front());
        return ans;
    }
};
