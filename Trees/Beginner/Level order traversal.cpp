// Problem Link : https://www.geeksforgeeks.org/problems/level-order-traversal/1

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
        queue<Node*> q;
        vector<int> ans;
      
        if(root == NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            ans.push_back(node->data);
            
            if(node->left != NULL)
                q.push(node->left);
                
            if(node->right != NULL)
                q.push(node->right);
        }
        
        return ans;
        
    }
};
