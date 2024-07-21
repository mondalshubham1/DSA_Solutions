// Problem Link : https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            if(umap.find(nums[i]) == umap.end()) {                    // As I have to list the unique pairs, I'll consider the elements that hasn't been considered so far.
                if(umap.find(nums[i]+k) != umap.end())
                    ans++;
                if(umap.find(nums[i]-k) != umap.end())
                    ans++;   
            }
            else {
                if(umap[nums[i]] == 1 && k==0) {                     // if k=0, you'll only consider only the second occurrence of each element.
                    ans++;
                }
            }
            umap[nums[i]]++;     
        }
        return ans;
    }
};
