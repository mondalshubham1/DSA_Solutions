// Problem Link : https://www.geeksforgeeks.org/problems/sum-tree/1

class Solution
{
    public:
    int TreeSum(Node* root, bool& isST){
      if(root == NULL)
          return 0;
			
  		if(root->left==NULL && root->right==NULL){
              return root->data;
          }
              
          long long leftSum = TreeSum(root->left, isST);
          long long rightSum = TreeSum(root->right, isST);
          
          if(root->data != leftSum+rightSum)
              isST = false;
              
          return leftSum+rightSum+(root->data);
    }
    bool isSumTree(Node* root)
    {
        bool isST=true;
        TreeSum(root, isST);
        return isST;
    }
};
