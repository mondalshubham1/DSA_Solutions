// Problem Link : https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;

        int left=1;
        int right=nums.size()-2;
        int mid;

        while(left <= right) {
            mid = (left+right)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){      // if mid is the peak element, then it'll be greater than its neighbours
                return mid;
            }
            if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){      // follow the upward slope
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return mid;
    }
};
