/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    int find_dis(Node* root,int x, int dis){
        if(root==NULL)
        return -1;
        
        if(root->data==x)
        return dis;
        
        int left=find_dis(root->left, x,dis+1);
        
        if(left!=-1)
        return left;
        
        return find_dis(root->right, x,dis+1);
    }
    
    Node* help(Node* root,int a,int b){
        if(root==NULL || root->data==a || root->data==b)
        return root;
        Node*left=help(root->left,a,b);
        Node*right=help(root->right,a,b);
        if(left==NULL)
        return right;
        if(right==NULL)
        return left;
        else
        return root;
    }
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node*lca=help(root,a,b);
        
        int d1=find_dis(lca,a,0);
        int d2=find_dis(lca,b,0);
        
        return d1+d2;
    }
};