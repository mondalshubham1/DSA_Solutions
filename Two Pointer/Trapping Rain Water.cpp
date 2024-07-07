// Problem Link : https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = height[0];
        int right_max = height[height.size()-1];
        int l=1;
        int r=height.size()-2;

        int water_storage = 0;

        while(l<=r){
            if(left_max<=right_max){                                 // if you left_max is smaller than right_max, the height of water on top of l is bottlenecked by left_max
                water_storage += max(0, left_max-height[l]);         // I can definitely determine the height on top of l
                left_max = max(left_max, height[l]);                 // update the l_max             
                l++;                                                 // take l to the right
            }
            else{     // if you right_max is smaller than left_max, the height of water on top of r is bottlenecked by r_max
                water_storage += max(0, right_max-height[r]);    
                right_max = max(right_max, height[r]);
                r--;
            }
        }
        return water_storage;
    }
};
