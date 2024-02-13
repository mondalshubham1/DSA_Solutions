class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        n-=2;
        while(n > 0){
            int tmp=a;
            a = b;
            b = b+tmp;
            n--;
        }
        return b;
    }
};
