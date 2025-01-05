// Problem Link : https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        q.push(root);

        while(!q.empty()) {
            vector<int> level_elements;
            int level_count = q.size();

            for(int i=0; i<level_count; i++) {
                TreeNode* node = q.front();

                q.pop();
                level_elements.push_back(node->val);
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);                
            }

            ans.push_back(level_elements);
        }

        return ans;
    }
};
