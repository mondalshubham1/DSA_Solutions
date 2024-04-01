// Problem Link : https://leetcode.com/problems/longest-palindrome/description/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto x: s){
            if(mp.find(x) == mp.end())
                mp[x] = 1;
            else
                mp[x]++;
        }
        int even_length = 0;
        int oddLengthPresent = 0;
        for(auto x: mp){
            if(x.second % 2) {
                oddLengthPresent = 1;
                even_length += x.second-1;
            }
            else
                even_length += x.second;
        }
        return even_length+oddLengthPresent;
    }
};
