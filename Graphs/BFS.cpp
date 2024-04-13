// Problem Link : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        queue<int> q;
        vector<int> result;
        
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            
            for(auto x: adj[node]) {
                if(!visited[x]) {
                    visited[x]=1;
                    q.push(x);
                }
            }
        }
        
        return result;
    }
};
