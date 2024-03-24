// Problem Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    void inorderTraversal(TreeNode* root, int i, int j, map<int,multiset<pair<int,int>>>& ans_map) {
        if(root==NULL)
            return;
        
        ans_map[j].insert({i,root->val});

        inorderTraversal(root->left, i+1, j-1, ans_map);
        inorderTraversal(root->right, i+1, j+1, ans_map);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, multiset<pair<int,int>>> ans_map;
        inorderTraversal(root, 0, 0, ans_map);
        for(auto x: ans_map){
            vector<int> v;
            for(auto y: x.second){
                v.push_back(y.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
