// Problem Link : https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = height[0];
        int right_max = height[height.size()-1];
        int l=1;
        int r=height.size()-1;

        int water_storage = 0;

        while(l<=r){
            if(left_max<=right_max){
                water_storage += max(0, left_max-height[l]);
                left_max = max(left_max, height[l]);
                l++;
            }
            else{
                water_storage += max(0, right_max-height[r]);
                right_max = max(right_max, height[r]);
                r--;
            }
        }
        return water_storage;
    }
};
