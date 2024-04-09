// Problem Link : https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> DP(n+1, 0);
        for(int i=1; i<=n; i++) {
            if(i%2)                                   
                DP[i] = DP[i>>1]+1;
            else
                DP[i] = DP[i>>1];
        }
        return DP;
    }
};
