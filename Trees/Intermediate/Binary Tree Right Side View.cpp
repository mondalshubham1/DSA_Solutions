// Problem Link : https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;

        if(root == NULL)
            return ans;

        q.push(root);
        int count=1;

        while(!q.empty()) {
            for(int i=0; i<count; i++) {
                TreeNode* tmp = q.front();
                if(i==count-1)
                    ans.push_back(tmp->val);

                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
                q.pop();
            }
            count = q.size();
        }
        return ans;
    }
};
