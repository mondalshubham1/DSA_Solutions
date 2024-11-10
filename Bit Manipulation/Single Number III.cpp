// Problem Link : https://leetcode.com/problems/single-number-iii/description/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_val = 0;
        for(auto x : nums)
            xor_val = xor_val ^ x;            // Take the XOR of all the elements, which will result in XOR of the two unique elements

        int k=1;
        while((xor_val&1) == 0) {
            xor_val = xor_val >> 1;
            k++;                             // Find the first bit position from the right side where both the unique elements differ, say k
        }

        int zero_bucket = 0;              
        int one_bucket = 0;

        for(auto x : nums) {
            if(((x>>k-1)&1) == 0)             // Put all the elements that whose kth bit is 1 in one bucket
                zero_bucket = zero_bucket^x;
            else
                one_bucket = one_bucket^x;    // Put all the elements that whose kth bit is 0 in zero bucket
        }
        // at kth bit, both the unique elements differ for sure, hence zero_bucket xor and one_bucket xor will result in both the unique elements.
        return {zero_bucket, one_bucket};   
    }
};
