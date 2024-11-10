// Problem Link : https://leetcode.com/problems/hamming-distance/description/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while(n) {
            if(n&1)
                count++;
            n = n>>1;
        }
        return count;
    }
};
