class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       if(n==0){
            vector<string> v;
            v.push_back("");
            return v;
       }
            

      for(int i=0; i<n ; i++){
          vector<string> a=generateParenthesis(i);
          vector<string> b=generateParenthesis(n-1-i);
          for(auto x : a) {
              for(auto y : b){
                  ans.push_back("(" + x + ")" + y);
              }
          }
      }
      return ans;
    }
};
