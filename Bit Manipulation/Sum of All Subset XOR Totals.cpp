// Problem Link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/


// Backtracking solution

class Solution {
public:
    void helper(int pos, vector<int>& nums, int& partial_ans, int& ans) {
        if(pos == nums.size()){
            ans += partial_ans;
            return;
        }

        helper(pos+1, nums, partial_ans, ans);           // Exclude the element in pos index
        partial_ans ^= nums[pos];                        // Include the element in pos index
        helper(pos+1, nums, partial_ans, ans);        
        
        partial_ans ^= nums[pos];                        // Cleaning step in backtracking
        
    }

    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int partial_ans = 0;
        helper(0, nums, partial_ans, ans);
        return ans;
    }
};
