// Problem Link : https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &A) {
    int sum=0;
    vector<int> ans;
    int left=-1;
    int right=-1;
    int ans_len=INT_MIN;
    
    unordered_map<int, int> sum_map;                          // stores the sum value as key, and the value as least index i such that A[0] + A[1] + A[2] +.....+ A[i] = sum value
    sum_map[0]=-1;
    
    for(int i=0; i<A.size(); i++) {
        sum+=A[i];
        if(sum_map.find(sum) != sum_map.end()) {             // find if there is an index such that A[0] + A[1] + A[2] +.....+ A[index] = sum, it means A[index+1] + A[index+2] +....+ A[i] = 0
            if(i-sum_map[sum] > ans_len){                    // strictly greater ensures that the first occurrence of such zero sum subarray is considered
                ans_len = i-sum_map[sum];
                left = sum_map[sum]+1;
                right = i;
            }
        }
        else {
            sum_map[sum] = i;
        }
    }
    
    if(left != -1 && right != -1) {
        for(int i=left; i<=right; i++)
            ans.push_back(A[i]);
    }
    return ans;
}
