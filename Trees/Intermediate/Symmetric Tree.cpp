// Problem Link : https://leetcode.com/problems/symmetric-tree/description/

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
    bool mirrorImage(TreeNode* p, TreeNode* q) {       // returns me if tree rooted at p & q are mirror images of each other or not
        if(p == NULL || q == NULL){
            if(p==NULL && q==NULL)     // both p & q are NULL
                return true;
            else                        // exactly one of them is NULL
                return false;
        }
        return (p->val==q->val) && mirrorImage(p->left, q->right) && mirrorImage(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return mirrorImage(root->left, root->right);     // for the original tree, check whether left subtree and right subtree are mirror images or not.
    }
};
