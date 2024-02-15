int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> DP(n, 0);
    DP[0] = max(A[0][0], A[1][0]);
    DP[1] = max(DP[0], max(A[0][1], A[1][1]));
  
    for(int i=2; i<n ; i++) {                                       // DP[i] = for A's 2xi, what's the answer, there are two options
        DP[i] = max(DP[i], DP[i-1]);                            // your answer at DP[i] won't have anything from the i th column, then DP[i] = DP[i-1]
        DP[i] = max(DP[i], max(A[0][i], A[1][i]) + DP[i-2]);    // your answer at DP[i] would have something from the i th column, then taking an element from (i-1) th column is not allowed, hence DP[i] = max(A[0][i]+ DP[i-2], A[1][i]+ DP[i-2]) 
    }
    return DP[n-1];
}
