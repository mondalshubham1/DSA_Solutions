// Problem Link : https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void helper(int pos, int sum, vector<int>& partial_ans, vector<int>& nums, vector<vector<int>>& ans) {
        if(sum == 0)
        {
            ans.push_back(partial_ans);
            return;
        }

        if(pos == nums.size() || nums[pos] > sum)
        {
            return;
        }

        // In the combination if you don't include nums[pos]
        helper(pos+1, sum, partial_ans, nums, ans);

        // If you include nums[pos]
        partial_ans.push_back(nums[pos]);
        helper(pos, sum-nums[pos], partial_ans, nums, ans);
        partial_ans.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> partial_ans;
        vector<vector<int>> ans;
        helper(0, target, partial_ans, candidates, ans);
        return ans;
    }
};
