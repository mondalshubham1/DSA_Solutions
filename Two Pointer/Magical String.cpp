// Problem Link : https://leetcode.com/problems/magical-string/description/

class Solution {
public:
    int magicalString(int n) {
        if(n<=3) {
            return 1;
        }
        int final_ans = 1;
        string magical_string = "122";                   // Simulating the given logic in the code via code       
        int curr_index = 2;
        char c = '1';
        while(magical_string.size() < n) {
            for(int i=0; i<(magical_string[curr_index]-'0'); i++) {
                magical_string += c;
                if(c == '1' && magical_string.size() <= n)
                    final_ans++;
            }
            curr_index++;
            if(c == '1')
                c='2';
            else
                c='1';    
        }
        return final_ans;
    }
};
