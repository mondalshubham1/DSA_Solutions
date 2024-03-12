// Problem Link : https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length() <= 10)
            return ans;

        unordered_map<string, int> umap;
        for(int i=0; i+9<s.length(); i++){
            string substr = s.substr(i,10);
            if(umap.find(substr) != umap.end()){
                if(umap[substr]==1){
                    ans.push_back(substr);
                    umap[substr]++;
                } 
            }
            else
                umap[substr]=1;
        }
        return ans;
    }
};
