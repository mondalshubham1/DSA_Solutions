// Problem Link : https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        long long left=0;
        long long right=x;
        long long mid;
        
        while(left<right){
            mid = (left+right)/2;
            if(mid*mid <= x && (mid+1)*(mid+1) > x)            // if mid value is the answer
                return mid;
            if(mid*mid > x)                                    // if mid is greater than root(x)
                right=mid-1;
            else
                left=mid+1;                                    // else case
        }
        return left;
    }
};
