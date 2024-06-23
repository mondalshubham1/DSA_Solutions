// Problem Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

// Recursive solution

class Solution {
public:
    int helper(queue<int>& q, int k) {
        if(q.size() == 1)
            return q.front();

        for(int i=1; i<k; i++) {
            int f = q.front();
            q.pop();
            q.push(f);
        }
        q.pop();
        return helper(q, k);
    }
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n ; i++)
            q.push(i);

        return helper(q, k);
    }
};
