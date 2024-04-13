class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> umap;                                // map an element to its index
        for(int i=0 ; i<arr.size() ; i++) {
            umap[arr[i]] = i;
        }

        int ans = INT_MIN;                                          // we store our answer here

        vector<vector<int>>memset(arr.size(), vector<int>(arr.size(), -1));                        // 2-D array used for memoization

        int n = arr.size(); 
        for(int j=n-1; j>=1 ; j--){                          // start evaluating memset in this order so that we can make sure that dependent memset values are already evaluated
            for(int i=j-1; i>=0; i--){
                if(umap.find(arr[i] + arr[j]) == umap.end()){              // memset[i][j] = longest fibonacci subsequence with first element as ith index element and second element as jth index element. 
                    memset[i][j] = 2;                                      // once we have the first and second element defined, the whole sequence is defined.
                }                                                          // memset[i][j] = 1 + memset[j][umap[arr[i]+arr[j]]]
                else {
                    int next_index = umap[arr[i] + arr[j]];
                    memset[i][j] = 1+memset[j][next_index];
                }
                ans = max(ans, memset[i][j]);
            }
        }
        return ans == 2 ? 0 : ans;
    }
};
