// Problem Link : https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& grid, int& count, int empty_sq, int& ans){
        // i, j is the starting point, grid is the input matrix, count stores the number of empty squares I've encountered in the path before reaching (i,j)
        
        count++;          // I'll land in that i,j if that's a non-obstacle square.

        if((grid[i][j] == 2) && count == empty_sq){     // I've reached the end point using a valid path  
            ans++;    
            count--;
            return;
        }

        int og_grid_val = grid[i][j];
        grid[i][j] = -1;                // the position has been visited, mark as an obstacle.

        // 4-directional movement
    
        // down
        if(i+1<grid.size() && grid[i+1][j] != -1)
            helper(i+1, j, grid, count, empty_sq, ans);
        
        // up
        if(i-1>=0 && grid[i-1][j] != -1)
            helper(i-1, j, grid, count, empty_sq, ans);

        // right
        if(j+1<grid[0].size() && grid[i][j+1] != -1)
            helper(i, j+1, grid, count, empty_sq, ans);

        // left
        if(j-1>=0 && grid[i][j-1] != -1)
            helper(i, j-1, grid, count, empty_sq, ans);

        // No more decisions to explore so perform Backtracking cleaning step.
        count--;
        grid[i][j] = og_grid_val;       // restoring the original grid value         
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;        // maintained a variable count that will tell me how many non-obstacle points I've encountered in a certain path.
        int ans = 0;          // final answer that I'll return, it'll get incremented when all the conditions are met.

        int empty_sq = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] >= 0)   // 0, 1, 2 all are non-obstacle.
                    empty_sq++;
            }
        }        // count number of non-obstacle points, how many 0's are there
    

        int start_i, start_j;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    start_i=i;
                    start_j=j;
                }      
            }
        }           // find the start position

        helper(start_i, start_j, grid, count, empty_sq, ans);
        return ans;    // tells me how many valid paths I've found
    }
};
