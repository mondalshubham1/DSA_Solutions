class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans = INT_MIN;

        while(i < j) {
            ans = max(ans, min(height[j], height[i])*(j-i));

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
