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
    Node* bst(vector<int>&arr, int start, int end){
        if(start>end)
        return NULL;
        
        int mid=(start +end)/2;
        
        Node *root=new Node(arr[mid]);
        
        root->left=bst(arr,start,mid-1);
        root->right=bst(arr,mid+1,end);
        
        return root;
    }
  public:
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        return bst(arr,0,n-1);
    }
};