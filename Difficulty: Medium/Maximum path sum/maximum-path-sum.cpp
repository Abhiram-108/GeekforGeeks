/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    int help(Node*root,int &maxsum){
        if(root==NULL)
        return 0;
        
        int left=max(help(root->left,maxsum),0);
        int right=max(help(root->right,maxsum),0);
        
        maxsum=max(root->data+left+right,maxsum);
        
        return root->data+max(left,right);
    }
  public:
    int findMaxSum(Node *root) {
        // code here
        if(root==NULL)
        return 0;
        
        int maxsum=INT_MIN;
         help(root,maxsum);
         
         return maxsum;
    }
};