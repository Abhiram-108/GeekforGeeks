/*
Node structure is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// modify the BST and return its root

void help(Node* root, int &sum) {
    if(root == NULL)
        return;
    
    help(root->right, sum);
    
    sum += root->data;
    root->data = sum;
    
    help(root->left, sum);
}

Node* modify(Node* root) {
    // Your code here
    if(root==NULL)
    return root;
   int sum=0;
   help(root,sum);
   return root;
}
