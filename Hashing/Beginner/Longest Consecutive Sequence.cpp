// Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            uset.insert(nums[i]);
        }

        for(int i=0; i<nums.size(); i++) {
            if(uset.find(nums[i]-1) == uset.end()) {
                int num = nums[i];
                int count=0;
                while(uset.find(num) != uset.end()) {
                    count++;
                    num++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
