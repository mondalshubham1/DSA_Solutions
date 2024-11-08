// Problem Link : https://leetcode.com/problems/word-break/

class Solution {
public:
    bool helper(int i, string s, vector<string>& wordDict, unordered_map<int, bool>& umap){
        // This function returns if string s[i : end] can be word-breaked or not given the wordDict
      
        if(i == s.length())           // Base case
            return true;

        if(umap.find(i) != umap.end())          // If the answer to the subproblem is already memoized, directly return the answer
            return umap[i];
        
        string tmp="";
        bool ans = false;

        for(int j=i; j<s.length(); j++) {
            tmp += s[j];               // For every prefix substring starting with i, check whether that prefix exists in the wordDict or not
            if(find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end())
              ans = ans || helper(j+1, s, wordDict, umap);    // if you find one such prefix, also check whether s[j+1 : end] can be word-breaked or not
        }

        umap[i] = ans;
        return umap[i];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> umap;
        return helper(0, s, wordDict, umap);
    }
};
