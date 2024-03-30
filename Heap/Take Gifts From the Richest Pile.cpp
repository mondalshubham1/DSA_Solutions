// Problem Link : https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0; i<gifts.size(); i++){
            pq.push(gifts[i]);
        }

        for(int i=0; i<k; i++){
            int pile = pq.top();
            pq.pop();
            int new_pile = sqrt(pile);
            pq.push(new_pile);
        }

        long long sum=0;
        while(!pq.empty()){
            int pile = pq.top();
            sum+=pile;
            pq.pop();
        }
        return sum;
    }
};
