// Problem Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p,q);    // if both the values are greater than the root, it means root->right is not null and I'm supposed to find the LCA in the right subtree
        }
        else if(root->val > p->val && root->val > q->val) {   // if both the values are samller than the root, it means root->left is not null and I'm supposed to find the LCA in the left subtree
            return lowestCommonAncestor(root->left, p,q);
        }
        
        return root;     // if none of the above conditions are met, then the current root is the LCA
        
    }
};
