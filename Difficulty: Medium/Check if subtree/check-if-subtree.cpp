/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};class Solution {
    bool ismirror(Node* t1, Node* t2) {
        if (t1 == NULL && t2 == NULL)
            return true;
        if (t1 == NULL || t2 == NULL)
            return false;
        if (t1->data != t2->data)
            return false;
        return ismirror(t1->left, t2->left) && ismirror(t1->right, t2->right);
    }

public:
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) {
        if (S == NULL)
            return true;
        if (T == NULL)
            return false;

        if (ismirror(T, S))
            return true;

        // check left and right subtrees
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};

 */

class Solution {

    
 void help(string &s,Node* root) {
    if (root == NULL)
        return;
    
    s+=root->data-'0';
    help(s,root->left);
    help(s,root->right);
   
}

  public:
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        
        string s1="";
        string s2="";
     help( s1,T);
     help( s2,S);
     if(s1.find(s2)!=string::npos)
     return 1;
     return 0;
    }
};