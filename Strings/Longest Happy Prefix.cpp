// Problem Link : https://leetcode.com/problems/longest-happy-prefix/description/

// Find the LPS array for the given string, Take the last entry of the LPS array, say x and your answer will be s[0...x]
// Reference : https://medium.com/@aakashjsr/preprocessing-algorithm-for-kmp-search-lps-array-algorithm-50e35b5bb3cb

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n,0);

        int index = 1;
        int len = 0;

        while(index < n) {
            if(s[index] == s[len]) {
                len++;
                lps[index]=len;
                index++;
            }
            else {
                if(len==0)
                    index++;
                else
                    len=lps[len-1];
            }
        }
        lps[index-1]=len;
        return s.substr(0, len);
    }
};
