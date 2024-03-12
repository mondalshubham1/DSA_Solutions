// Problem Link : https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    int max_len = INT_MAX;
    for(int i=0; i<A.size(); i++){
        int l = A[i].length();
        max_len = min(max_len, l);
    }
    
    bool stop = false;
    string ans = "";
    
    for(int i=0; i<max_len; i++){
        char c = A[0][i];
        for(int j=1; j<A.size(); j++){
            if(A[j][i] != c){
                stop=true;
                break;
            }
        }
        if(!stop)
            ans += c;
        else
            break;
    }
    return ans;
}
