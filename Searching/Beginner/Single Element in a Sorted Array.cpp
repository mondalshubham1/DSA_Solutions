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

            if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1])) {                      // When the mid element is neither equal to the left nor right, it means that element is the unique element
                return nums[mid];
            }

            if(mid%2 == 0){                   // means you have even number of elements to the left of mid, i.e. between left-----mid-1
                if(nums[mid] == nums[mid+1])                // all elements to the left of mid are in pairs and unique element will be there to the right of mid
                    left=mid+2;
                else
                    right = mid-2;
            }
            else{                            // means you have odd number of elements to the left of mid, i.e. between left-----mid-1
                if(nums[mid] == nums[mid+1])
                    right=mid-1;
                else 
                    left = mid+1;
            }  
        }
        return nums[mid];
        
    }
};
