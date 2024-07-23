// Problem Link : https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, INT_MAX);
      
        /*
          memo[i] = minimum coins needed for making i amount.      i=0,1,2,3,.....,amount
          You choose each coin, say coins[j] and find the minimum coins needed to make the i-coins[j],
          or you may not choose coins[j], so the amount you need to make is i only
          then find the minimum among all of them. 
          memo[i] = min(memo[i-coins[j]])  for all 0<=j<n
        */
      
        memo[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                if(coins[j] <= i && memo[i-coins[j]] != INT_MAX)
                    memo[i] = min(memo[i], memo[i-coins[j]]+1);
            }
        }

        for(int x: memo)
            cout << x << endl;

        return memo[amount]==INT_MAX ? -1 : memo[amount];
        
    }
};
