// Problem Link : https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution {
public:
    bool static distance(vector<int> a, vector<int> b){
        return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);

        // return true if a <= b
        // return false if a > b
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), distance);

        for(int j=0; j<k ; j++)
            ans.push_back(points[j]);
        return ans;
    }
};
