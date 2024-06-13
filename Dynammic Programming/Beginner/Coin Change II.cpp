// Problem Link : https://leetcode.com/problems/coin-change-ii/description/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> memo(n+1, vector<int>(amount+1, 0));
        
        /* 
            memo[i][j] = Number of ways you can make a coin change for j amount with coins from coins[i:end]
            Case 1 : You choose to have ith coin in your coin change, then total ways you can do it is memo[i][j-coins[i]]
            Case 2 : You decide not to choose the ith coin in your coin change, the total ways you can do it is memo[i+1][j]
        */
        
        memo[n][0] = 1;
        for(int j=0; j<=amount; j++) {
            for(int i=n-1; i>=0; i--) {
                memo[i][j] = memo[i+1][j];
                if(j>=coins[i])
                    memo[i][j] += memo[i][j-coins[i]];
            }
        }
    
        return memo[0][amount];
    }
};
