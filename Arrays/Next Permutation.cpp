// Problem Link : https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=nums.size()-1;
        while(index>0 && nums[index] <= nums[index-1]){                        // find the index from where we have a decreasing sequence to the end of the array
            index--;
        }
        reverse(nums.begin()+index, nums.end());                               // we need to reverse it, as we're at the end of all the possible permutations in the subarray[index...end]
        
        if(index==0)                                                           // if the whole array is in decreasing order, it means we have exhausted all the permutations, and we need to start again
            return;
        
        int bigger_index=index;                                                // else we need to find the next bigger element that can be put at index-1.
        while(nums[bigger_index]<=nums[index-1]){
            bigger_index++;
        }

        swap(nums[index-1], nums[bigger_index]);
        return;
    }
};
