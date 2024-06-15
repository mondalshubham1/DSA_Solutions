// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(left<=right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < nums[right]) {        // Case 1 : mid element is among the smaller elements
                if(target > nums[mid] && target <= nums[right]){
                    left = mid+1;
                }
                else
                    right=mid-1;
            }

            else {
                if(target < nums[mid] && target >= nums[left]){               // Case 2 : mid element is among the greater elements
                    right=mid-1;
                }
                else
                    left=mid+1;
            }
        }
        return -1;
    }
};
