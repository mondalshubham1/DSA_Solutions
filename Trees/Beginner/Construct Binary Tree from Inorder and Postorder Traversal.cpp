// Problem link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    // Helper function takes a part of inorder array and a part of postorder array and creates a tree out of it and returns the root of the same.
    TreeNode* helperFunc(vector<int>& inorder, vector<int>& postorder, int inorder_i, int inorder_j, int postorder_i, int postorder_j) {
        if(inorder_i > inorder_j){             // Base condition
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postorder_j]);                                       // Given an inorder and postorder traversal for any particular tree, the root of the tree will be the last element of the postorder traversal
        int root_val = postorder[postorder_j];
        
        int root_index;                                                                             // You can find that root in the inorder traversal too at some index say, root_index, all the elements left to root_index will be the inorder traversal of left subtree to root
        for(int i=inorder_i; i<=inorder_j; i++)                                                     // All the elements to the right of root_index will be the inorder_traversal of the right subtree to root
        {
            if(inorder[i] == root_val){
                root_index = i;
                break;
            }
        }

        /*
          If we can find the post order traversal of the left and right subtree from the given postorder traversal array, then we can create the whole trees out of inorder and postorder traversal of left and right subtrees.
          In the given post order traversal, we know the left most elements are postorder traversal of left subtree, and after that postorder traversal of right subtree starts, and the element is the root. 
          We know that number of elements in the inorder traversal and post order traversal is same for the left and right subtree, say the length is len.
          Hence in the given postorder traversal, the first len number of elements will be the postorder traversal of left subtree and rest is the postorder traversal of right subtree.
        */

        root->left = helperFunc(inorder, postorder, inorder_i, root_index-1, postorder_i, postorder_i+root_index-inorder_i-1);                // recursively creating the subtrees given the inorder and postorder traversal arrays
        root->right = helperFunc(inorder, postorder, root_index+1, inorder_j, postorder_i+root_index-inorder_i, postorder_j-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helperFunc(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
