// Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> sum_map;
        sum_map[0]=1;

        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            if(sum_map.find(sum-k) != sum_map.end()) {
                ans+=sum_map[sum-k];
            }
            if(sum_map.find(sum) == sum_map.end())
                sum_map[sum]=1;
            else
                sum_map[sum]++;
        }
        return ans;
    }
};
