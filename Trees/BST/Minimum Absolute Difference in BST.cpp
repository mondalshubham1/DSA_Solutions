// Problem Link : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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

/*          -- without using recursion --
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* currNode=root;
        stack<TreeNode*> s;
        int prev_num = -1;
        int ans = INT_MAX;

        while(!s.empty() || currNode!=NULL){
            if(currNode == NULL) {
                TreeNode* node=s.top();
                if(prev_num != -1)
                    ans=min(ans,abs(node->val-prev_num));
                prev_num = node->val;    
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
*/

/***
    Idea is to do inorder traversal, but instead of printing the root, we will include the value of abs(root->val-previous element printed). In both approach we do the same.
***/

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
    void helper(TreeNode* root, int& prev, int& ans) {
        if(root == NULL)
            return;
        
        helper(root->left, prev, ans);

        if(prev!=-1){
            ans = min(ans, abs(root->val-prev));
        }
        prev = root->val;

        helper(root->right, prev, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev=-1;
        int ans=INT_MAX;
        helper(root, prev, ans);
        return ans;
    }
};
