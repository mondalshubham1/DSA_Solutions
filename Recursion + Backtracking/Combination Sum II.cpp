// Problem Link : https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
    void helper(int pos, int sum, vector<int>& partial_ans, vector<int>& nums, vector<vector<int>>& ans) {
        if(sum == 0) {
            ans.push_back(partial_ans);
            return;
        }
        if(pos == nums.size() || nums[pos] > sum) {
            return;
        }
        
        // take nums[pos]
        partial_ans.push_back(nums[pos]);
        helper(pos+1, sum-nums[pos], partial_ans, nums, ans);
        partial_ans.pop_back();

        // As the array is sorted, all the duplicate elements will be adjacent to each other
        // this loop will take you to the last occurrence of nums[pos]
        while(pos < nums.size()-1 && nums[pos] == nums[pos+1]) pos++;

        // don't take nums[pos]
        helper(pos+1, sum, partial_ans, nums, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> partial_ans;
        vector<vector<int>> ans;
        helper(0, target, partial_ans, candidates, ans);
        return ans;
    }
};
