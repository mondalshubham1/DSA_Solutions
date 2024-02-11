class Solution {
public:
    int helper(int pos, vector<int>& nums){
        if(pos == nums.size()-1){
            long long sr = sqrt(nums[pos-1]+nums[pos]);
            if(sr*sr == nums[pos-1]+nums[pos]){
                return 1;
            }
            else
                return 0;
        }

        int res = 0;
        unordered_set<int> uset;
        for(int i=pos; i<nums.size(); i++) {
            if(uset.find(nums[i]) == uset.end()) {          
                long long sr = sqrt(nums[pos-1]+nums[i]);
                if(sr*sr == nums[pos-1]+nums[i]){
                    uset.insert(nums[i]);
                    swap(nums[pos], nums[i]);
                    res += helper(pos+1, nums);
                    swap(nums[pos], nums[i]);
                }
            }
        }
        return res;
    }

    int numSquarefulPerms(vector<int>& nums) {
        int ans=0;
        unordered_set<int> uset;
        for(int i=0; i<nums.size(); i++){
            if(uset.find(nums[i]) == uset.end()){
                uset.insert(nums[i]);
                swap(nums[i], nums[0]);
                ans+=helper(1, nums);
                swap(nums[i], nums[0]);
            }
        }
        return ans;
    }
};
