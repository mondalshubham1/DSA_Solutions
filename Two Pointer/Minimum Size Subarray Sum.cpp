// Problem Link : https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int ans = INT_MAX;

        int window_sum=nums[0];                                // stores the sum of elements between i and j

        // For each i, find the smallest subarray starting from i with sum more than or equal to target.
        while(i<n){
            while(j<n-1 && window_sum<target) {                // iterate your j till your window sum is not greater than or equal to target
                j++;
                window_sum+=nums[j]; 
            }
            if(window_sum<target)                              // even after the above loop you cannot make window sum greater than or equal to zero means you can never make it.
                break;
            ans = min(ans, j-i+1);                 // For that i, i upto j is the smallest window that has sum more than or equal to target.
            window_sum -= nums[i];                 
            i++;                                   // Now we'll try to find the smallest such window for the next i.
        }

        return ans==INT_MAX ? 0 : ans;
    }
};
