// Problem Link : https://leetcode.com/problems/permutations/description/

class Solution {
public:
    void helper(int pos, vector<int> &nums, vector<vector<int>> &ans){
        if(pos == nums.size()){
            // come at the end of the branch.
            ans.push_back(nums);
            return;
        }

        for(int i=pos; i<nums.size(); i++){
            swap(nums[pos], nums[i]);        // keeping all elements in the pos index.
            helper(pos+1, nums, ans); 
            swap(nums[i], nums[pos]);        // cleaning is done.
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;     // storing my answer here
        helper(0, nums, ans);
        return ans;
    }
};
