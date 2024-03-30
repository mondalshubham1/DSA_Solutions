// Problem Link : https://leetcode.com/problems/binary-tree-paths/description/

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
    void inorder(TreeNode* root, string partial_ans, vector<string>& ans){                  // Approach similar to backtracking
        if(root->left != NULL)
            inorder(root->left, partial_ans+to_string(root->val)+"->", ans);
        
        if(root->right != NULL)
            inorder(root->right, partial_ans+to_string(root->val)+"->", ans);

        if(root->left==NULL && root->right==NULL){
            ans.push_back(partial_ans+to_string(root->val));
        } 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string partial_ans="";
        vector<string> ans;
        inorder(root, partial_ans, ans);
        return ans;
    }
};
