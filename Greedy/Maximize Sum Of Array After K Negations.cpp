// Problem Link : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {
            pq.push(-1*nums[i]);
            sum += nums[i];
        }
        while(k--) {
            int min_val = pq.top();
            min_val = -1*min_val;
            cout << min_val << endl;
            sum -= 2*min_val;
            pq.pop();
            pq.push(min_val);  
        }
        return sum;
    }
};
