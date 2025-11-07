// User function Template for C++

/*// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};*/

class Solution {
    void help(vector<vector<int>>&res,Node*root,int target,vector<int>&path){
        if(root==NULL)
        return;
        
        path.push_back(root->key);
        if(target==root->key){
            res.push_back(path);
           
        }
       
            help(res,root->left,target-root->key,path);
            help(res,root->right,target-root->key,path);
        
        path.pop_back();
        
        return;
    }
  public:
    vector<vector<int>> printPaths(Node *root, int sum) {
        // code here
        vector<vector<int>>res;
        vector<int>path;
        help(res,root,sum,path);
        
        return res;
    }
};