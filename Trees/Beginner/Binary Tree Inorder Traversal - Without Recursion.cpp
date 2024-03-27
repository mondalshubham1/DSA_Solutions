// Problem Link : https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* currNode=root;
        stack<TreeNode*> s;
        vector<int> ans;

        while(!s.empty() || currNode!=NULL){
            if(currNode == NULL) {
                TreeNode* node=s.top();
                ans.push_back(node->val);
                currNode=node->right;
                s.pop();
            }
            else {
                s.push(currNode);
                currNode = currNode->left;
            } 
        }
        return ans;
    }
};
