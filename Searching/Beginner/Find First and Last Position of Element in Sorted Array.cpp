// Problem Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        if(nums[0] == target)
            return 0;

        int left = 1;
        int right = nums.size()-1;

        while(left <= right) {
            int mid = (left+right)/2;

            if(nums[mid-1] != target && nums[mid] == target)
                return mid;

            else if(nums[mid]<target)
                left = mid+1;
            
            else
                right = mid-1;
        }
        return -1;
    }

    int lastOccurence(vector<int>& nums, int target) {
        if(nums[nums.size()-1] == target)
            return nums.size()-1;

        int left = 0;
        int right = nums.size()-2;

        while(left <= right) {
            int mid = (left+right)/2;

            if(nums[mid+1] != target && nums[mid] == target)
                return mid;

            else if(nums[mid]<=target)
                left = mid+1;
            
            else
                right = mid-1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return {-1, -1};
        }
        int first_occurrence = firstOccurence(nums, target);
        int last_occurrence = lastOccurence(nums, target);

        return {first_occurrence, last_occurrence};
    }
};
