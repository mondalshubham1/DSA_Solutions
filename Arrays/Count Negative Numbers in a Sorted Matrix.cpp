// Problem Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        /* 
          Given the 2-D martix is both row-wise and column-wise sorted, from left to right  and from top to down the values decrease
          Here, we start iterating from the bottom left element, if we go right, the values going to decrease, and we go up, the values increase
          Here the following approach will return the solution in O(m+n) time
        */
      
        int ans = 0;
        int i = row-1;
        int j = 0;
        while(1) {
            // If you traverse in right direction where the values are decreasing, as soon as you get a negative value, you'll get only negative values further in that direction.
            while(j<col && grid[i][j] >= 0){       
                j++;
            }
            ans += col-j;           // For that row this will give me the number of negative values
            if(j>=col)
                break;

            int tmp = i;             
// As soon as I get a negative value, I'll travel up where the values increase and will stop only once I get a non-negative value, all values after that will be non-negative.
            while(i>=0 && grid[i][j] < 0) {
                i--;
            }
            ans += (tmp-i-1)*(col-j); 

            if(i<0)
                break;
        }
        return ans;
    }
};
