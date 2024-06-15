// Problem Link : https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        if(nums.size()==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];

        int left=2;
        int right=nums.size()-3;
        int mid;

        while(left<=right) {
            mid=(left+right)/2;

            if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1])) {
                return nums[mid];
            }

            if(mid%2 == 0){
                if(nums[mid] == nums[mid+1])
                    left=mid+2;
                else
                    right = mid-2;
            }
            else{
                if(nums[mid] == nums[mid+1])
                    right=mid-1;
                else 
                    left = mid+1;
            }  
        }
        return nums[mid];
        
    }
};
