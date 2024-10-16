// Problem Link : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;

        int i=0; int j=0;
        unordered_map<int, int> umap;
        long long window_sum = 0;

        while(j<nums.size()) {
            if(umap.find(nums[j]) != umap.end()) {
                while(i<=umap[nums[j]]) {
                    umap.erase(nums[i]);
                    window_sum -= nums[i];
                    i++;
                }
            }
            umap[nums[j]] = j;
            window_sum += nums[j];
            if(j-i+1 == k) {
                ans = max(ans, window_sum);
                umap.erase(nums[i]);
                window_sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};
