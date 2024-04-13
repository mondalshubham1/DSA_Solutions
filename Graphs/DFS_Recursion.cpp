// Problem Link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void dfsUtil(int i, vector<int> adj[], vector<int>& visited, vector<int>& result) {
        visited[i] = 1;
        result.push_back(i);
        for(auto x : adj[i]) {
            if(!visited[x])
                dfsUtil(x, adj, visited, result);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> result;
        dfsUtil(0, adj, visited, result);
        return result;
    }
};
