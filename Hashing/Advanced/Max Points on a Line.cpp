// Problem Link : https://leetcode.com/problems/max-points-on-a-line/description/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0; i<points.size(); i++){                              
            /*
              For each point, find the slopes of all other points with that fixed point.
              Make a map that keeps a count of all different slopes made with that fixed point. 
              All the point having the same slope with that fixed point will all lie in the same line.
              So, we can find the slope of the line that passes through that given point and has maximum number of other points lying on it.
              Similarly we can find the same for all other points, and finally we take the max out of them as our answer.
            */
            unordered_map<double, int> umap;                             
            int max_count = 0;
            for(int j=i+1; j<points.size(); j++){
                double slope;
                if(points[j][1] == points[i][1])
                    slope = 0;
                else if(points[j][0] == points[i][0])
                    slope = INT_MAX;
                else
                    slope = (double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);

                if(umap.find(slope) != umap.end()) {
                    umap[slope]++;
                }
                else
                    umap[slope]=1;
                
                max_count = max(max_count, umap[slope]);
            }
            ans = max(ans, max_count);
        }
        return ans+1;
    }
};
