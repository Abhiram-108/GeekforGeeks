/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
    int help(Node*root,int target){
        if(root==NULL)
        return 0;
        
        if(root->left==NULL && root->right==NULL)
        return target==root->data;
        
        int l=help(root->left,target-root->data);
        int r=help(root->right,target-root->data);
        
        
        return l||r;
    }
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        return help(root,target);
    }
};