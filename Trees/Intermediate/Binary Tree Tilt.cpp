// Problem Link : https://leetcode.com/problems/binary-tree-tilt/description/

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
    int sumTree(TreeNode* root, int& tilt) {
        if(root == NULL)
            return 0;
        
        int leftTreeSum = sumTree(root->left, tilt);
        int rightTreeSum = sumTree(root->right, tilt);
        tilt += abs(leftTreeSum-rightTreeSum);

        return (root->val)+leftTreeSum+rightTreeSum;

    }
    int findTilt(TreeNode* root) {
        int tilt=0;
        sumTree(root, tilt);
        return tilt;
    }
};
