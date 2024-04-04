//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
  void f(vector<int>&ans,Node*root){
      if(root==NULL)
      return;
      if(root->left)
      f(ans,root->left);
      ans.push_back(root->data);
      if(ans,root->right)
      f(ans,root->right);
  }
  int merge(vector<int>& arr, vector<int> temp, int left, int mid, int right) {
    int inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;
    // Merge the two halves while counting the number of inversions
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    // Copy the remaining elements of the left half to the temp array
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    // Copy the remaining elements of the right half to the temp array
    while (j <= right)
        temp[k++] = arr[j++];
    // Copy the sorted temp array back to the original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    // Return the number of inversions
    return inv_count;
}
  int merge_Sort(vector<int>& arr, vector<int> &temp, int left, int right) {
    int mid, inv_count = 0;
    // If the array has more than one element, divide it into halves and merge them
    if (right > left) {
        mid = (left + right) / 2;
        // Recursively sort and merge the left half
        inv_count += merge_Sort(arr, temp, left, mid);
        // Recursively sort and merge the right half
        inv_count += merge_Sort(arr, temp, mid + 1, right);
        // Merge the two halves while counting the number of inversions
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    // Return the number of inversions
    return inv_count;
}

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        int c=0;
        vector<int>ans;
        f(ans,root);
        vector<int>temp(n);
        return merge_Sort(ans, temp, 0, n - 1) ;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends