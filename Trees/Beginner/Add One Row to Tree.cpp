// Problem Link : https://leetcode.com/problems/add-one-row-to-tree/description/

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
    void inOrderTraversal(TreeNode* root, int depth, int desiredDepth, int val) {
        if(root == NULL)
            return;
        
        inOrderTraversal(root->left, depth+1, desiredDepth, val);
        if(depth == desiredDepth){
            TreeNode* tmpLeft = root->left;
            root->left = new TreeNode(val);
            root->left->left = tmpLeft;

            TreeNode* tmpRight = root->right;
            root->right = new TreeNode(val);
            root->right->right = tmpRight; 
        }
        inOrderTraversal(root->right, depth+1, desiredDepth, val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* tmp = root;
            root = new TreeNode(val);
            root->left = tmp;
            return root;
        }
        inOrderTraversal(root, 1, depth-1, val);
        return root;
    }
};
