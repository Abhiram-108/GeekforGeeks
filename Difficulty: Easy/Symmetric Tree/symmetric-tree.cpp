/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
    int help(Node*left,Node*right){
           if(left==NULL || right==NULL)
        return left==right;
        if(left->data!=right->data)
        return 0;
        return help(left->left,right->right) && help(left->right,right->left);
    }
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if(root->left==NULL && root->right==NULL)
        return true;
        return help(root->left,root->right);
    }
};