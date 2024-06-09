// Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 1;
        int right = nums.size()-1;

        while(left <= right) {
            int mid = (left + right)/2;

            if(nums[mid] < nums[mid-1])              // When the mid element is lesser than the previous element then that's the answer
                return nums[mid];

            if(nums[mid] > nums[right])              // In this case the minimum value lies on the right side of mid
                left = mid+1;
            else
                right = mid-1;                       // In this case the minimum value lies on the left side of mid
        }
        return nums[0];              // this condition only hits, when we have a completely sorted array
    }
};
