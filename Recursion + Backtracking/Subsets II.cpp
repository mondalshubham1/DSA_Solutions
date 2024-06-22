// Problem Link : https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void helper(int pos, vector<int>& partial_ans, vector<int>& nums, vector<vector<int>>& ans) {
        if(pos == nums.size())
        {
            ans.push_back(partial_ans);
            return;
        }

        // Case 1 : When you choose the element at pos index
        partial_ans.push_back(nums[pos]);
        helper(pos+1, partial_ans, nums, ans);
        partial_ans.pop_back();

        // Case 2 : Don't choose nums[pos], and also make sure you never choose it
        while(pos < nums.size()-1 && nums[pos]==nums[pos+1]) pos++;

        helper(pos+1, partial_ans, nums, ans);
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());         // sort the elements so that the duplicate elements are adjacent
        vector<int> partial_ans;
        vector<vector<int>> ans;
        helper(0, partial_ans, nums, ans);
        return ans;
    }
};
