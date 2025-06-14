/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
    private:
    void help(Node*root,vector<vector<int>>&ans,int level){
        if(root==NULL)
        return;
        if(level>=ans.size()){
            vector<int>temp;
            ans.push_back(temp);
        }
        ans[level].push_back(root->data);
        help(root->left,ans,level+1);
        help(root->right,ans,level+1);
        
        return;
        
    }
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>res;
        help(root,ans,0);
        int n=ans.size();
        for(int i=0;i<n;i+=2)
        reverse(ans[i].begin(),ans[i].end());
        for(auto it:ans){
            for(auto it1:it){
                res.push_back(it1);
            }
        }
        return res;
    }
};