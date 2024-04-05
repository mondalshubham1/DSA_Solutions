// Problem Link : https://www.interviewbit.com/problems/assign-mice-to-holes/

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ans = INT_MIN;
    for(int i=0; i<A.size(); i++) {
        ans = max(ans, abs(A[i]-B[i]));
    }
    return ans;
}

/*
  Greedy Logic : Suppose all mice at ith index goes in ith index hole, except two say m and n, where mth mouse will go to nth index hole and vice versa. You'll see that doesn't matter the 
  positions of the holes, you cannot create a better answer than the greedy logic.
*/
