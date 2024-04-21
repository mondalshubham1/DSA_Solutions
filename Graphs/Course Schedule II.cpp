// Problem Link : https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    void dfs(int i, vector<vector<int>>& edgeList, stack<int>& s, vector<int>& visited, int& isDAG) {
        if(isDAG == 0) return;
        visited[i]=1;
        for(auto x: edgeList[i]) {
            if(visited[x] == 0)
                dfs(x, edgeList, s, visited, isDAG);
            else if(visited[x] == 1){
                isDAG = 0;
                return;
            }
        }
        visited[i]=2;
        s.push(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edgeList(numCourses, vector<int>());
        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            edgeList[u].push_back(v);
        }
        vector<int> visited(numCourses, 0);
        stack<int> s;
        int isDAG=1;

        for(int i=0; i<numCourses; i++) {
            if(visited[i]!=2 && isDAG!=0)
                dfs(i, edgeList, s, visited, isDAG);
        }
      
        vector<int> ans;
        if(!isDAG)
            return ans;

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
