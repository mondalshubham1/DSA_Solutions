// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> DP(n+1, vector<int>(2,0));

        for(int i=n-1; i>=0; i--){
            // For 0th index, you're not allowed buy, either you'll sell, or keep holding the stock.
            int sell = prices[i]+DP[i+1][1];
            int hold = DP[i+1][0];
            DP[i][0] = max(sell, hold);

             // For 1th index, you're allowed to buy, either you'll buy, or skip buying the stock.
            int buy = -prices[i]+DP[i+1][0];
            int skip = DP[i+1][1];
            DP[i][1] = max(buy, skip);
        }

        return DP[0][1];
    }
};
