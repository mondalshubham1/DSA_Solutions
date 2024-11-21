// Problem Link : https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto x : nums) {
            if(umap.find(x) == umap.end())
                umap[x] = 1;
            else
                umap[x] += 1;
        }

        priority_queue<pair<int,int>> pq;
        for(auto x : umap) {
            pair<int, int> entry_ele;
            entry_ele.first = x.second;
            entry_ele.second = x.first;
            pq.push(entry_ele);
        }
        vector<int> ans;
        for(int i=0; i<k; i++) {
            pair<int,int> ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};
