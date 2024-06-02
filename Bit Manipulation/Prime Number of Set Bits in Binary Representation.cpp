// Problem Link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while(num > 0)
        {
            count += num&1;
            num = num >> 1;
        }
        return count;
    }

    int countPrimeSetBits(int left, int right) {
        unordered_set<int> prime_set({2,3,5,7,11,13,17,19,23,29,31});
        int ans = 0;

        int num = left;
        while(num <= right) {
            if(prime_set.find(countSetBits(num)) != prime_set.end()){
                ans++;
            }
            num++;
        }
        return ans;
    }
};
