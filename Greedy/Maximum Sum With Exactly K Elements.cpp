// Problem Link : https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_value = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            max_value = max(max_value, nums[i]);
        }
        int ans = ((max_value+k-1)*(max_value+k) - (max_value)*(max_value-1))/2;
        return ans; 
    }
};
