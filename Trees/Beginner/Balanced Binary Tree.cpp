// Problem Link : https://leetcode.com/problems/balanced-binary-tree/description/

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
    int depth(TreeNode* root, bool& ans) {
        if(root == NULL)
            return -1;

        int left_height = depth(root->left, ans);
        int right_height = depth(root->right, ans);
        if(abs(left_height-right_height)>1)        // balance condition check for each node, absolute difference between the left and right subtree height should not be more than 1.
            ans = false;

        return max(left_height, right_height)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        depth(root, ans);                  // find the left and right height subtree for each node and check the balance condition for each node.
        return ans;
    }
};
