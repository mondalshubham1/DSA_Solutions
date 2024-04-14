// Problem Link : https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> DP(n+1, vector<int>(m+1, 0));

        for(int i=0; i<=n; i++)
            DP[i][0] = i;

        for(int j=0; j<=m; j++)
            DP[0][j] = j;

        for(int j=1; j<=m; j++){
            for(int i=1; i<=n; i++){
                if(word1[i-1] == word2[j-1]){
                    DP[i][j] = DP[i-1][j-1];
                }
                else{
                    vector<int> tmp{DP[i-1][j-1] , DP[i-1][j] , DP[i][j-1]};
                    sort(tmp.begin(), tmp.end());
                    DP[i][j] = 1+tmp[0];
                }
            }
        }

        return DP[n][m];
    }
};
