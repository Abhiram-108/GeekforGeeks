/*The structure of Node

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

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        int ans=-1;
        while(root!=NULL){
            if(root->data>  x->data){
                ans=root->data;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return ans;
    }
};