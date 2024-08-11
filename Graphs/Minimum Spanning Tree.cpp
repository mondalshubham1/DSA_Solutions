// Problem Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Prim's algorithm to find MST

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> visited(V, 0);                                                              // visited array
        priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> pq;    // Min Heap
        
        pq.push({0,0});              // any one of the node is pushed
        
        int ans=0;                
        
        while(!pq.empty()) {
            pair<int, int> tmp = pq.top();           // take the minimum weight edge, and the corresponding node
            
            int v = tmp.second;
            int w = tmp.first;
            
            pq.pop();
            
            if(visited[v] == 1)                     // if that node is already visited, leave it
                continue;
                
            visited[v] = 1;                         
            ans += w;                               // if that node is not visited, mark it as visited and add it into the answer
            for(auto x : adj[v]) {        
                int n = x[0];
                int w = x[1];   
                if(visited[n] == 0)                 // take all other nodes adjacent to that node into consideration the next time
                    pq.push({w,n});
            }
        }
        return ans;
    }
};
