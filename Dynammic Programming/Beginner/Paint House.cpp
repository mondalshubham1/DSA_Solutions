// Problem Link : https://www.interviewbit.com/problems/paint-house/

int Solution::solve(vector<vector<int> > &A) {
    int noOfHouses = A.size();
    vector<vector<int>> dp(noOfHouses, vector<int>(3,0));
    
    // Base cases are set
    dp[noOfHouses-1][0] = A[noOfHouses-1][0];
    dp[noOfHouses-1][1] = A[noOfHouses-1][1];
    dp[noOfHouses-1][2] = A[noOfHouses-1][2];
    
    // dp[i][0] = minimum cost to paint the house with the first house as red
    // dp[i][1] = minimum cost to paint the house with the first house as blue
    // dp[i][2] = minimum cost to paint the house with the first house as green
    for(int i=noOfHouses-2; i>=0; i--) {
        dp[i][0] = A[i][0] + min(dp[i+1][1], dp[i+1][2]);
        dp[i][1] = A[i][1] + min(dp[i+1][0], dp[i+1][2]);
        dp[i][2] = A[i][2] + min(dp[i+1][0], dp[i+1][1]);
    }
    
    return min(dp[0][2],min(dp[0][0], dp[0][1]));
}
