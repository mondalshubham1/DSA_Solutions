// Problem Link : https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    int nthUglyNumber(int n) {
        int count = 0;
        priority_queue<long long> pq;
        pq.push(-1);
        unordered_set<long long> uset;
        uset.insert(1);

        while(count < n-1) {
            long long x = pq.top();
            //cout << x << endl;
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
