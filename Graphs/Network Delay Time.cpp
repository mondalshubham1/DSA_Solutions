// Problem Link : https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj_list(n+1, vector<pair<int, int>>());
        for(auto x : times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            adj_list[u].push_back(make_pair(v, w));
        }

        vector<int> delay(n+1, INT_MAX);
        delay[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, k));

        while(!pq.empty()) {
            pair<int, int> min_ele = pq.top();
            int dist = min_ele.first;
            int u = min_ele.second;
            pq.pop();
            if(dist > delay[u]) continue;

            for(auto x : adj_list[u]){
                int v = x.first;
                int d = x.second;

                if(dist+d < delay[v]) {
                    delay[v] = dist+d;
                    pq.push(make_pair(dist+d, v));
                }
            }

        }

        int ans = INT_MIN;
        for(int i=1; i<delay.size(); i++) {
            ans = max(ans, delay[i]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
