// Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        int j=0;

        while(j<nums.size()){
            while(j+1<nums.size() && nums[j]==nums[j+1])
                j++;

            if(j == nums.size()-1)
                break;
            nums[index+1] = nums[j+1];
            index++;
            j++;
        }
        return index+1;
    }
};
