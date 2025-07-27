class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void help(Node* root) {
        if (!root) return;

        path.push_back(root->data); // add current node to path

        // If leaf node, save the current path
        if (!root->left && !root->right) {
            ans.push_back(path);
        } else {
            if (root->left) help(root->left);
            if (root->right) help(root->right);
        }

        path.pop_back(); // backtrack
    }

public:
    vector<vector<int>> Paths(Node* root) {
        ans.clear();
        path.clear();
        help(root);
        return ans;
    }
};
