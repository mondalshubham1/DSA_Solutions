// Problem Link : https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    int nthUglyNumber(int n) {
        int count = 0;
        priority_queue<long long> pq;      // maintain a heap of elements containing the next possible Ugly Number
        pq.push(-1);
        unordered_set<long long> uset;     // to have a track which elements are already there in your heap
        uset.insert(1);

        while(count < n-1) {               // Take out the first n-1 Ugly numbers
            long long x = pq.top();
            pq.pop();
            if(uset.find(x*2) == uset.end()){
                pq.push(x*2);
                uset.insert(x*2);
            }
                
            if(uset.find(x*3) == uset.end()){
                pq.push(x*3);
                uset.insert(x*3);
            }

            if(uset.find(x*5) == uset.end()){
                pq.push(x*5);
                uset.insert(x*5);
            }
            count++;
        }
        return -1*pq.top();
    }
};
