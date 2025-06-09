/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
    private:
    int help(Node*root){
        if(root==NULL)
        return 0;
        int l=help(root->left);
        int r=help(root->right);
        if(l==-1 || r==-1)
        return -1;
        if(abs(l-r)>1)
        return -1;
        return 1+max(l,r);
    }
  public:
    bool isBalanced(Node* root) {
        // Code here
        int ans=help(root);
        if(ans!=-1)
        return true;
        return false;
    }
};