// Problem Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums)
            sum+=x;
        
        if(sum%2)
            return false;

        int n = nums.size();

        vector<vector<bool>> memo(n, vector<bool>(sum/2+1,false));     // memo[i][j] = Is it possible to have a sum j from elements between i index to the end

        if(nums[n-1]<=sum/2)              // base cases, boundary cases in the tabulation approach
            memo[n-1][nums[n-1]] = true;

        for(int i=0; i<n; i++){          // base cases, boundary cases in the tabulation approach
            memo[i][0] = true;
        } 

        // memo[i][j] = either you choose ith element in the sum j (memo[i+1][j-nums[i]]) || either you don't choose ith element in the sum j (memo[i+1][j])
        for(int j=1; j<sum/2+1; j++) {
            for(int i=n-2; i>=0; i--) {
                if(j-nums[i]>=0)
                    memo[i][j] = memo[i+1][j-nums[i]] || memo[i+1][j];
                else
                    memo[i][j] = memo[i+1][j];
            }
        }

        return memo[0][sum/2];                    // we're deciding if we have a set of elements in the whole array with sum (sum of array)/2
    }
};
