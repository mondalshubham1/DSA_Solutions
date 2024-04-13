// Problem Link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        stack<int> s;
        vector<int> result;
        
        s.push(0);
        
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            
            if(visited[node])
                continue;
            
            visited[node]=1;
            result.push_back(node);
            
            for(int i=adj[node].size()-1; i>=0; i--) {
                if(!visited[adj[node][i]])
                    s.push(adj[node][i]);
            }
        }
        return result;
    }
};
