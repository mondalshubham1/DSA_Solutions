class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans = INT_MIN;

        while(i < j) {
            ans = max(ans, min(height[j], height[i])*(j-i));          // Find the water you can store between ith line and jth line
            
            /*
                If height of ith line is smaller then there cannot be any other line to the right of i with height smaller than ith line that will give me more water storage.
                Hence I will increment my i to the point till I get height more than the original.
            */
            
            if(height[i] <= height[j]) {                              
                int m=i;
                while(m<j && height[m]<=height[i]){
                    m++;
                }
                ans = max(ans, min(height[j], height[m])*(j-m));
                i = m;
            }
            else {
                int n=j;
                while(n>i && height[n]<=height[j]){
                    n--;
                }
                ans = max(ans, min(height[i], height[n])*(n-i));
                j = n;
            }
        }
        return ans;
    }
};
