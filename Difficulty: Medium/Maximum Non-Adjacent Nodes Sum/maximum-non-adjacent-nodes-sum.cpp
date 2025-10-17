/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    vector<int>help(Node*root){
        if(root==NULL){
            vector<int>ans(2,0);
            return ans;
        }
        vector<int>left=help(root->left);
        vector<int>right=help(root->right);
        
        vector<int>a(2);
        a[0]=root->data+left[1]+right[1];
        a[1]=max(left[1],left[0])+max(right[1],right[0]);
        
        return a;
    }
  public:
    int getMaxSum(Node *root) {
        // code here
        vector<int>ans=help(root);
        return max(ans[0],ans[1]);
    }
};