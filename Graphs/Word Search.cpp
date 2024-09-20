// Problem Link : https://leetcode.com/problems/word-search/description/

class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j, string word, int k,  vector<vector<bool>>& visited, int& ans) {
        if(k==word.length()-1 && word[k]==board[i][j]) {   // if you've reached your last character and the character matches, then return with true
            ans = true;
            return;
        }

        if(word[k] != board[i][j]) {         // if the current board character doesn't match with the required word character then return
            return;
        }

        visited[i][j] = true;
        int rows = board.size();
        int cols = board[0].size();

        if(i+1<rows && !visited[i+1][j])
            helper(board, i+1, j, word, k+1, visited, ans);         // apply DFS considering all four sides

        if(i-1>=0 && !visited[i-1][j])
            helper(board, i-1, j, word, k+1, visited, ans);

        if(j+1<cols && !visited[i][j+1])
            helper(board, i, j+1, word, k+1, visited, ans);

        if(j-1>=0 && !visited[i][j-1])
            helper(board, i, j-1, word, k+1, visited, ans);

        visited[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = false;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(ans == true)
                    return true;
                helper(board, i, j, word, 0, visited, ans);
            }
        }
        return ans;
    }
};
