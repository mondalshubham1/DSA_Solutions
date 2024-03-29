// Problem Link : https://www.geeksforgeeks.org/problems/odd-even-level-difference/1

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       
       bool isOdd=true;
       int ans_sum=0;
       
       while(!q.empty()){                                         // This is how you can identify all the elements in a particular level.
            int level_size=q.size();
            for(int i=0; i<level_size; i++) {
                Node* frontNode = q.front();
                
                if(isOdd)
                    ans_sum += frontNode->data;
                else
                    ans_sum += -1*frontNode->data;
                    
                q.pop();
                if(frontNode->left != NULL)
                    q.push(frontNode->left);
                if(frontNode->right != NULL)
                    q.push(frontNode->right);
            }  
            isOdd = !isOdd;
       }
       return ans_sum;
    }
};
