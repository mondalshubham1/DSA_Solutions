class Solution {
public:
    bool isSubsequence(string s, string t) {
        int row = s.length();
        int col = t.length();

        bool DP[row+1][col+1];               // DP[i][j] returns if the s[i...end] is a subsequence of t[j...end] 

        DP[row][col] = true;
        for(int i=0; i<row ; i++){
            DP[i][col] = false;
        }
        for(int i=0; i<col ; i++){
            DP[row][i] = true;
        }

        for(int j=col-1; j>=0 ; j--) { 
            for(int i=row-1; i>=0 ; i--){
                if(s[i] == t[j])                                 // if s[i] and t[j] are the same then we need to check if s[i+1...end] is a subsequence of t[j+1...end]
                    DP[i][j] = DP[i+1][j+1];
                
                else
                    DP[i][j] = DP[i][j+1];                      // else if s[i] and t[j] are not same then we need to check if s[i...end] is a subsequence of t[j+1...end]
            }
        }

        return DP[0][0]; 
    }
};
