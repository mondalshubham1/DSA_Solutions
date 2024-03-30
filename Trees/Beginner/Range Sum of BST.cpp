// Problem Link : https://leetcode.com/problems/range-sum-of-bst/description/

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
class Solution {
public:
    void helper(TreeNode* root, int low, int high, int& ans){
        if(root == NULL)
            return;
        
        helper(root->left, low, high, ans);
        if(root->val<=high && root->val>=low)                        // Perform an inorder traversal, and when you come to any root, add it to the answer if the root is in range
            ans += root->val;
        helper(root->right, low, high, ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        helper(root, low, high, ans);
        return ans;
    }
};
