// Problem Link : https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(int i, vector<vector<int>>& edgeList, vector<int>& visited) {
        visited[i] = 1;
        for(auto x : edgeList[i]) {
            if(!visited[x])
                dfs(x, edgeList, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> edgeList(n, vector<int>());
        for(int i=0; i<n ; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && isConnected[i][j])
                    edgeList[i].push_back(j);
            }
        }

        int ans = 0;
        vector<int> visited(n, 0);    
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, edgeList, visited);
            }
        }
        return ans;
    }

};
