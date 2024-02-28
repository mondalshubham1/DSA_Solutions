// Problem Link : https://www.interviewbit.com/problems/painters-partition-problem/

bool isValid(int limit, int P, vector<int> &C) {
    int sum=0;
    for(int i=0 ; i<C.size() ; i++) {
        if(C[i] > limit) {
            return false;
        }
        if(sum+C[i]<=limit) {
            sum+=C[i];
        }
        else {
            sum = C[i];
            P--;
            if(P == 0)
                return false;
        }
    }
    if(P>=1){
        return true;
    }
}

/*
  The minimum value of ans can be maximum out of all the units in the array C, in the case when we have painters and everyone is given one unit to paint, say left.
  The maximum value of ans can be sum of all the units in the array C, in the case when we make just 1 painter to paint all the units, say right.
  For mid value in the range  [left, right], we partition the board in such a way so that no painter will paint more that mid units, we'll check if there exists such partition or not. 
  If such partition exist, that mid value is a candidate for the final answer, but we need an answer as minimum as possible, hence we'll again search for our answer in the left half of the array.
  If such partition doesn't exist, it means either we don't have enough number of painters or some unit is more than mid value, so definitely all elements in the left half will fail, so we'll go to the right half.
  So we applied a Binary Search over the range.
*/

int Solution::paint(int A, int B, vector<int> &C) {
    long long ans;
    
    long long left = INT_MIN;
    for(auto x : C){
        if(x > left)
            left = x;
    }
    
    long long right = 0;
    for(auto x : C)
        right+=x;
  
    while(left <= right) {
        long long mid = (left + right)/2;
        if(isValid(mid, A, C)){
            ans = mid;
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    
    return (B*ans)%10000003;
}
