// Problem Link : https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

void dfs(int i, vector<vector<int>>& edgeList, vector<int>& visited, int& ans){   // Trying to find if the graph has any directed cycles or not
    if(ans == 0) return;
    visited[i] = 1;          // current depth first search is going
    for(auto x: edgeList[i]){
        if(visited[x] == 0)
            dfs(x, edgeList, visited, ans);
        else if(visited[x] == 1){
            ans=0;
            return;   
        }
    }
    visited[i] = 2;          // means the node has been processed
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> edgeList(A, vector<int>());
    
    for(int i=0; i<B.size(); i++) {
        int u = B[i]-1;
        int v = C[i]-1;
        
        edgeList[u].push_back(v);
    }
    
    vector<int> visited(A, 0);
    int ans=1;
    
    for(int i=0; i<A; i++) {
        if(visited[i]!=2 && ans==1)
            dfs(0, edgeList, visited, ans);   
    }
    return ans;  
}
