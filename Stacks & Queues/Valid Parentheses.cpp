// Problem Link : https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isClosing(char c, char top) {
        if(c == ')' && top == '(')
            return true;
        else if(c == '}' && top == '{')
            return true;
        else if(c == ']' && top == '[')
            return true;
        else
            return false;           
    }

    bool isValid(string s) {
        stack<char> st;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if(!st.empty() && isClosing(c, st.top()))
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;

        return false;
    }
};
