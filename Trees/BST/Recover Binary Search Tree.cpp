// Problem Link : https://leetcode.com/problems/recover-binary-search-tree/description/

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
    void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& second) {                     // Doing traversal in increasing order of BST.
        if(root == NULL)
            return;
        
        inorder(root->left, prev, second);

        if(prev!=NULL && prev->val > root->val){
            second = prev;
            return;
        }
        prev=root;

        inorder(root->right, prev, second);
    }

    void outorder(TreeNode* root, TreeNode*& prev, TreeNode*& first) {                     // Doing traversal in decreasing order of BST.
        if(root == NULL)
            return;
        
        outorder(root->right, prev, first);

        if(prev!=NULL && prev->val < root->val){
            first = prev;
            return;
        }
        prev=root;

        outorder(root->left, prev, first);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* first;
        TreeNode* second;
        TreeNode* prev=NULL;
        inorder(root, prev, second);
        prev=NULL;
        outorder(root, prev, first);
        swap(first->val, second->val);
        return;
    }
};
