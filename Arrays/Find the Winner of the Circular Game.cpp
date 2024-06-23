// Problem Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

// Iterative solution

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n ; i++)
            q.push(i);

        while(q.size() > 1) {
            for(int i=1; i<k; i++) {
                int f = q.front();
                q.pop();
                q.push(f);
            }
            q.pop();
        }

        return q.front();
    }
};
