// Problem Link : https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:
    bool pathExists(int source, int dest, vector<vector<int>>& edges, vector<int>& visited) {         // Apply DFS from the source
        visited[source] = 1;

        if(source == dest)
            return true;

        bool final_decision = false;
        for(auto x: edges[source]) {         // A path will exist from the source if only if there exists a path from some of its adjacent nodes to the destination
            if(!visited[x])
                final_decision = final_decision || pathExists(x, dest, edges, visited);
        }
        return final_decision;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n, 0);
        vector<vector<int>> edgeList(n, vector<int>());

        for(auto x: edges){
            edgeList[x[0]].push_back(x[1]);
            edgeList[x[1]].push_back(x[0]);
        }
        return pathExists(source, destination, edgeList, visited);
    }
};
