/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    int help(Node*root, long long &maxi){
        if(root==NULL)
        return 0;
        
      long long  int left=help(root->left,maxi);
    long long    int right=help(root->right,maxi);
        
        maxi=max(maxi,left+right);
        return 1+max(left,right);
    }
  public:
    int diameter(Node* root) {
        // code here
        long long maxi=0;
     help(root,maxi);
     
     return maxi;
    }
};