// Problem Link : https://leetcode.com/problems/permutations-ii/description/

class Solution {
public:
    void helper(int pos, vector<int> &nums, vector<vector<int>> &ans){
        if(pos == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> u_set;                    // that's tracking all the elements that has already been considered in the pos index.

        // If an element is already considered in pos index, I shouldn't put that element in the pos index again, because it'll cause a duplicate branch.
        for(int i=pos; i<nums.size(); i++){
            if(u_set.find(nums[i]) == u_set.end())    // whether nums[i] has already been considered for that position or not.
            {
                u_set.insert(nums[i]);
                swap(nums[pos], nums[i]);
                helper(pos+1, nums, ans);
                swap(nums[i], nums[pos]);
            } 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};
