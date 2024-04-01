// Problem Link : https://leetcode.com/problems/longest-palindrome/description/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto x: s){                                  // make a frequency map
            if(mp.find(x) == mp.end())
                mp[x] = 1;
            else
                mp[x]++;
        }
        int even_length = 0;
        int oddLengthPresent = 0;
        
        // In a palindrome, there can be at max one character with odd frequency and rest of the character frequency has to be even
        
        for(auto x: mp){                                // for all odd frequencies, you can add the max even number, i.e. odd frequency-1.       
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
