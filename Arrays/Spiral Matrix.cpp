// Problem Link : https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ans;

        int x = min((rows+1)/2, (cols+1)/2);
        for(int i=0; i<x; i++) {
            goRight(i,i,rows,cols,ans,matrix);
            goDown(i,i,rows,cols,ans,matrix);
            if(rows > 1)
                goLeft(i,i,rows,cols,ans,matrix);
            if(cols > 1)
                goUp(i,i,rows,cols,ans,matrix);
            rows-=2;
            cols-=2;
        }

        return ans;
    }

    void goRight(int i, int j, int m, int n, vector<int>& ans, vector<vector<int>>& matrix) {
        for(int k=0; k<n; k++)
            ans.push_back(matrix[i][j+k]);
    }
    void goDown(int i, int j, int m, int n, vector<int>& ans, vector<vector<int>>& matrix) {
        for(int k=1; k<m; k++)
            ans.push_back(matrix[i+k][j+n-1]);
    }
    void goLeft(int i, int j, int m, int n, vector<int>& ans, vector<vector<int>>& matrix) {
        for(int k=1; k<n; k++)
            ans.push_back(matrix[i+m-1][j+n-1-k]);
    }
    void goUp(int i, int j, int m, int n, vector<int>& ans, vector<vector<int>>& matrix) {
        for(int k=1; k<m-1; k++)
            ans.push_back(matrix[i+m-1-k][j]);
    }

};
