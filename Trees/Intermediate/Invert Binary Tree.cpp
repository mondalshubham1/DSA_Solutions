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
    void helper(TreeNode* root) {        // Given a tree rooted at root, this function inverts that tree.
        if(root == NULL)                 // Base condition
            return;

        invertTree(root->left);         // invert the left subtree
        invertTree(root->right);        // invert the right subtree
        swap(root->left, root->right);  // swap the pointers of the left and right subtree
    } 

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
