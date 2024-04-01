// Problem Link : https://leetcode.com/problems/largest-perimeter-triangle/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int perimeter = 0;
        for(int i=nums.size()-1; i>=2; i--){
            if(nums[i-1]+nums[i-2] > nums[i]){                                  // Everytime I'm choosing the nums[i] as the base. Then I'm using the triange property, c > a+b
                perimeter = max(perimeter, nums[i]+nums[i-1]+nums[i-2]);
                break;
            }      
        }
        return perimeter;
    }
};
