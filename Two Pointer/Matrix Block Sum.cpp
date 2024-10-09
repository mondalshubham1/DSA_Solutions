// Problem Link : https://leetcode.com/problems/matrix-block-sum/description/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> prefix_sum(row, vector<int>(col, 0));

        for(int i=0; i<row; i++)
            prefix_sum[i][0] = mat[i][0];
        
        for(int i=0; i<row; i++) {
            for(int j=1; j<col; j++) {
                prefix_sum[i][j] += prefix_sum[i][j-1]+mat[i][j];
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cout << prefix_sum[i][j] << " ";
            }
            cout << endl;
        }

        vector<vector<int>> ans(row, vector<int>(col, 0));

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                int sum = 0;
                for(int x=-1*k; x<=k; x++) {
                    int right_row_index;
                    int right_col_index;
                    int left_row_index;
                    int left_col_index;
                    if(x<=0) {
                        if(i+x < 0)
                            continue;
                        else
                           right_row_index = i+x; 
                        
                        right_col_index = min(j+k, col-1);
                        left_row_index = right_row_index;
                        if(j-k-1<0){
                            sum+=prefix_sum[right_row_index][right_col_index];
                            continue;
                        }
                        else
                            left_col_index = j-k-1;
                    }
                    else
                    {
                        if(i+x >= row)
                            continue;
                        else
                           right_row_index = i+x;
                        right_col_index = min(j+k, col-1);
                        left_row_index = right_row_index;
                        if(j-k-1<0){
                            sum+=prefix_sum[right_row_index][right_col_index];
                            continue;
                        }
                        else
                            left_col_index = j-k-1;
                    }
                    sum += prefix_sum[right_row_index][right_col_index] - prefix_sum[left_row_index][left_col_index];
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};
