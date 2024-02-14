class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memset(amount+1, vector<int>(coins.size(), 0));
        int cols = coins.size();
        int rows = amount+1;
        for(int j=cols-1; j>=0 ; j--) {
            for(int i=1; i<rows ; i++) {
                memset[i][j] = INT_MAX;
                if(i >= coins[j] && memset[i-coins[j]][j] != -1) {
                    int f = 1+memset[i-coins[j]][j];
                    memset[i][j] = f;
                }
                if(j+1 < cols && memset[i][j+1] != -1) {
                    int s = memset[i][j+1];
                    memset[i][j] = min(memset[i][j], s);
                }
                if(memset[i][j] == INT_MAX)
                  memset[i][j] = -1;
            }
        }
        return memset[amount][0];   
    }
};
