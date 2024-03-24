// Problem Link : https://leetcode.com/problems/invert-binary-tree/description/

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
    void helper(TreeNode* root) {
        if(root == NULL)
            return;

        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    } 
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
