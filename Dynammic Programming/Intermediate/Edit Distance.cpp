// Problem Link : https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> DP(n+1, vector<int>(m+1, 0));              // Each DP[i][j] represents how many moves you'll need to convert first i characters of word1 to first j characters of word2 i.e. Edit distance.

        for(int i=0; i<=n; i++)
            DP[i][0] = i;                                              // convert i characters to 0 length, you'll have to remove characters i times.

        for(int j=0; j<=m; j++)                                            
            DP[0][j] = j;                                              // convert 0 character to j length, you'll have to insert characters j times.

        for(int j=1; j<=m; j++){
            for(int i=1; i<=n; i++){
                if(word1[i-1] == word2[j-1]){
                    DP[i][j] = DP[i-1][j-1];                           // if the last character is same, then we just have to convert first i-1 characters to j-1 characters.
                }
                else{                                                  // when last characters are not same.
                    vector<int> tmp{DP[i-1][j-1] , DP[i-1][j] , DP[i][j-1]};             // Case 1 : we replace the last character : DP[i-1][j-1] + 1
                    sort(tmp.begin(), tmp.end());                                        // Case 2 : we insert a new character at the end : DP[i][j-1] + 1
                    DP[i][j] = 1+tmp[0];                                                 // Case 3 : we delete the last character from the end : DP[i-1][j] + 1
                }
            }
        }

        return DP[n][m];
    }
};
