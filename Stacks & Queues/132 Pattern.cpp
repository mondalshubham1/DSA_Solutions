// Problem Link : https://leetcode.com/problems/132-pattern/description/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> s;
        int min_so_far = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            while(!s.empty() && s.top().first <= nums[i]) {
                s.pop();
            }
            if(!s.empty()) {
                if(s.top().second < nums[i]) {
                    return true;
                }
            }
            s.push({nums[i], min_so_far});
            min_so_far = min(min_so_far, nums[i]);
        }
        return false;
    }
};
