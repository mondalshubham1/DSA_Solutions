// Problem Link : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
public:

    /*
        We need to find the minimum computations to do for Ai*Ai+1*Ai+2*Ai+3...........Aj-1Aj
        We need to find all possible ways it can be done by partitioning
        First partition would be (Ai)*(Ai+1*Ai+2*Ai+3...........Aj-1*Aj)
        Next would be (Ai*Ai+1)*(Ai+2*Ai+3...........Aj-1*Aj)
        Next would be (Ai*Ai+1*Ai+2)*(Ai+3...........Aj-1*Aj)
        ....
        Last would be (Ai*Ai+1*Ai+2*Ai+3...........Aj-1)*(Aj)
    */

    int helper(int arr[], int i, int j, vector<vector<int>>& dp) {
        if(i==j)
            return 0;
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int mini = INT_MAX;
        for(int k=i; k<j; k++) {
            int val = helper(arr, i, k, dp) + helper(arr, k+1, j, dp) + arr[i]*arr[k+1]*arr[j+1];
            mini = min(mini, val);
        }
        
        dp[i][j] = mini;
        
        return mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N-1, vector<int>(N-1, -1));
        
        return helper(arr, 0, N-2, dp);
    }
};
