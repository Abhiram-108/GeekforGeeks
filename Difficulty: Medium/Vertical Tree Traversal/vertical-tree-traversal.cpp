/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
              mp[line].push_back(node->data);

            if (node->left)
                q.push({node->left, line - 1});
            if (node->right)
                q.push({node->right, line + 1});
        }
         for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};