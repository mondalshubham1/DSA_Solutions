// Problem Link : https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<long long>> paths(m, vector<long long>(n,0));

        paths[m-1][n-1] = obstacleGrid[m-1][n-1] != 1 ? 1 : 0;

        for(int j=n-2; j>=0; j--) {
            if(obstacleGrid[m-1][j] == 1)
                paths[m-1][j] = 0;
            else
                paths[m-1][j] = paths[m-1][j+1];
        }

        for(int i=m-2; i>=0; i--) {
            if(obstacleGrid[i][n-1] == 1)
                paths[i][n-1] = 0;
            else
                paths[i][n-1] = paths[i+1][n-1];
        }

        for(int i=m-2; i>=0; i--) {
            for(int j=n-2; j>=0; j--) {
                if(obstacleGrid[i][j] != 1) {
                    paths[i][j] = paths[i+1][j] + paths[i][j+1];
                }
            }
        }

        return paths[0][0];
    }
};
