// Problem Link : https://leetcode.com/problems/subsets/description/

class Solution {
public:
    void helper(int pos, vector<int>& partial_ans, vector<int> nums, vector<vector<int>>& ans) {
        if(pos == nums.size()) {
            ans.push_back(partial_ans);                 // Base case, no more elements to consider, store the partial_ans in a global ans variable.
            return;
        }

        helper(pos+1, partial_ans, nums, ans);          // don't take nums[pos]

        partial_ans.push_back(nums[pos]);
        helper(pos+1, partial_ans, nums, ans);          // take nums[pos]
        partial_ans.pop_back();                         // Cleaning step in Backtracking

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> partial_ans;
        helper(0, partial_ans, nums, ans);
        return ans;
    }
};
