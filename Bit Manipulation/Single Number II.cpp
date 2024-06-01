// Problem Link : https://leetcode.com/problems/single-number-ii/description/

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (const int num : nums)       
        sum += num >> i & 1;                     // Extracting the i th bit from each number, and summing all of them
      sum %= 3;                                  // if the number that appears exactly once has ith bit as 1, then the previously calculated sum will be of the form 3k+1 else 3k in case of 0   
      ans |= sum << i;                           // Recreating the the answer from individual bits
    }

    return ans;
  }
};
