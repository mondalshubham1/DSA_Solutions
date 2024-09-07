// Problem Link : https://leetcode.com/problems/search-insert-position/description/

// Pose this problem as finding the lowest index where number is greater than or equal to the given target.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start < end) {
            int mid = (start+end)/2;
            if(nums[mid] < target) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }

        if(nums[start] >= target) {
            return start;
        }
        else
            return start+1;
    }
};
