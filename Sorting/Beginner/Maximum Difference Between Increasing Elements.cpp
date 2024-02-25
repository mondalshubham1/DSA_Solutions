// Problem link : https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0;
        int max_value = 0;
        for(int i=nums.size()-1; i>=0 ; i--) {    
            max_value = max(max_value, nums[i]);                      // max_value stores the max value between i to end 
            ans = max(ans, max_value-nums[i]);
        }
        return ans==0 ? -1 : ans ;   
    }
};
