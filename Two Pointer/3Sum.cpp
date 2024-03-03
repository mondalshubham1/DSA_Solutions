// Problem Link : https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());           
        vector<vector<int>> ans;

        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;             
            int target = -1*nums[i];                  // choose nums[i] as the first element, then nums[j]+nums[k]=-1*nums[i], so that the sum of all three is 0
            int j = i+1;
            int k = nums.size()-1;

            while(j<k) {                             // applying Two Sum on the nums[i+1 : end]
                if(nums[j]+nums[k] == target){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int m=j+1;
                    int n=k-1;
                
                    while(m<=k && nums[m] == nums[m-1])      // find the right most value with the value arr[j], we're doing all this as we don't want duplicate pairs making a sum            
                        m++;
                    
                    while(j<=n && nums[n] == nums[n+1])      // find the left most value with the value arr[k] 
                        n--;

                    j = m;
                    k = n;
                }
                else if(nums[j]+nums[k] > target)
                    k--;
                else
                    j++;
            }

        }
        return ans;
    }
};
