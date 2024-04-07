// Problem Link : https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> DP(n+2,0);                        // DP[i] represents the maximum money you can rob from ith house to the end

        for(int i=n-1; i>=0 ; i--) {
            int rob_i = nums[i] + DP[i+2];                      // Case 1 : You rob ith house, then you cannot rob i+1 th house, you'll have to start robbing again from i+2 th house
            int dont_rob_i = DP[i+1];                           // Case 2 : You don't rob ith house, then you can start robbing from i+1 th house
            DP[i] = max(rob_i, dont_rob_i);                     // Take the maximum out from both the cases
        }

        return DP[0];
    }
};
