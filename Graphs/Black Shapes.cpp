// Problem Link : https://www.interviewbit.com/problems/black-shapes/

bool inBound(int i, int j, int n, int m) {
    if(i>=0 && i<n && j>=0 && j<m)
        return true;
    else
        return false;
}

void dfs(int i, int j, vector<string>& A, vector<vector<int>>& visited, int n, int m) {           // Applying DFS on one node will mark all black shapes adjacent to it within one component
    visited[i][j] = 1;
    if(inBound(i-1, j, n, m) && A[i-1][j] == 'X' && !visited[i-1][j]) 
        dfs(i-1, j, A, visited, n, m);
        
    if(inBound(i+1, j, n, m) && A[i+1][j] == 'X' && !visited[i+1][j]) 
        dfs(i+1, j, A, visited, n, m);
        
    if(inBound(i, j-1, n, m) && A[i][j-1] == 'X' && !visited[i][j-1]) 
        dfs(i, j-1, A, visited, n, m);
        
    if(inBound(i, j+1, n, m) && A[i][j+1] == 'X' && !visited[i][j+1]) 
        dfs(i, j+1, A, visited, n, m);      
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans=0;
    for(int i=0; i<n ; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] == 0 && A[i][j] == 'X') {
                dfs(i, j, A, visited, n, m);
                ans++;
            }
        }
    }
    return ans;
}
