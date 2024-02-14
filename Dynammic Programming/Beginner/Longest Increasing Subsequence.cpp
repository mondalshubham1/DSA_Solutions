class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int n=nums.size();
        vector<int> DP(n,1);                                // DP[i] = Longest increasing subsequence with the starting element as nums[i]
        DP[n-1] = 1;  
        for(int i=n-2 ; i>=0; i--) {
            for(int j=i+1; j<n ; j++){
                if(nums[j] > nums[i])
                    DP[i] = max(DP[i], DP[j]+1);           // DP[i] = max(DP[k]) where, k=[i+1, end] and nums[k] > nums[i]
            }
            ans = max(DP[i], ans);
        }
        return ans;
    }
};
