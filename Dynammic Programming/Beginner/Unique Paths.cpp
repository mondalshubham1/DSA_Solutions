// Problem Link : https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans = 0;
        vector<vector<int>> memo(m, vector<int>(n,0));

        for(int i=m-1; i>=0 ; i--)
            memo[i][n-1] = 1;

        for(int j=n-1; j>=0 ; j--)
            memo[m-1][j] = 1;

        for(int j=n-2; j>=0 ; j--) {
            for(int i=m-2; i>=0; i--){
                memo[i][j] = memo[i+1][j] + memo[i][j+1];
            }
        }
        return memo[0][0];
    }
};
