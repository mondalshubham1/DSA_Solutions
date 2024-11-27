// Problem Link : https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {                 // It's very similar to finding mode in a sorted array, inorder traversal of a BST will take me through the tree in sorted order.
public:
    void inorder(TreeNode* root, int& prev, int& prev_count, int& mode_count, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        inorder(root->left, prev, prev_count, mode_count, ans);

        //-------------------------------------------- Logic to implement when I am landing at a node ----------------------------------------
        
        if(root->val != prev) {                      // If your current element is not equal to your previous element                                           
            if(prev_count > mode_count) {            // Is the frequency of previous element greater than your max frequency so far?
                while(ans.size() > 0) {              // delete the previous answer
                    ans.pop_back();
                }
                ans.push_back(prev);                 // enter the previous element as your new answer
                mode_count = prev_count;             // your max frequency so far would be your previous element frequency
            }
            else if(prev_count == mode_count && prev!=INT_MIN)     // if your previous element frequency is equal to the max frequency so far 
                ans.push_back(prev);                               //  add the prev element in the ans
 
            prev_count = 1;                          
        }
        else {                                        // If your current element is equal to your previous element
            prev_count++;
        }
        prev = root->val;
        
        //------------------------------------------------------------------------------------------------------------------------------------
        
        inorder(root->right, prev, prev_count, mode_count, ans);
    }

    vector<int> findMode(TreeNode* root) {
        int prev_count=0;
        int prev=INT_MIN;
        int mode_count=0;
        vector<int> ans;
        inorder(root, prev, prev_count, mode_count, ans);
        if(prev_count > mode_count) {
            while(ans.size() > 0) {
                ans.pop_back();
            }
            ans.push_back(prev);
        }
        else if(prev_count == mode_count && prev!=INT_MIN)
            ans.push_back(prev);

        return ans;
    }
};
