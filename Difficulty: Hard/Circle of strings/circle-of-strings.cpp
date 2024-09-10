//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define vi vector<int>
#define vvi vector<vi>
class Solution {
  public:
   // Helper function for Depth-First Search (DFS) to check connectivity
    void dfs(int node, vvi &graph, vector<bool> &visited) {
        visited[node] = true; // Mark the current node as visited
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, graph, visited); // Recursively visit all connected nodes
            }
        }
    }

    // Function to check if the strings can form a circle
    int isCircle(vector<string> &arr) {
        int n = arr.size(); // Number of strings in the array
        vvi graph(26); // Adjacency list representing the graph (26 letters of the alphabet)
        vi inDegree(26, 0), outDegree(26, 0); // Arrays to store in-degrees and out-degrees

        // Step 1: Construct the graph and track in-degrees and out-degrees
        for(int i = 0; i < n; ++i) {
            string str = arr[i];
            int u = str[0] - 'a'; // First letter of the string
            int v = str.back() - 'a'; // Last letter of the string

            // Add directed edge from u to v
            graph[u].push_back(v);
            outDegree[u]++; // Increase out-degree of u
            inDegree[v]++; // Increase in-degree of v
        }

        // Step 2: Check if in-degree matches out-degree for every node
        for(int i = 0; i < 26; ++i) {
            if(inDegree[i] != outDegree[i]) {
                return 0; // If any node has unequal in-degree and out-degree, return 0 (not possible)
            }
        }

        // Step 3: Check if all nodes with non-zero degree are in the same connected component
        vector<bool> visited(26, false); // Track visited nodes
        int startNode = arr[0][0] - 'a'; // Start DFS from the first letter of the first string
        dfs(startNode, graph, visited); // Perform DFS to mark all reachable nodes

        // Step 4: Ensure all nodes with non-zero in-degree or out-degree are visited
        for(int i = 0; i < 26; ++i) {
            if((inDegree[i] > 0 || outDegree[i] > 0) && !visited[i]) {
                return 0; // If any node is not visited, return 0 (graph is not fully connected)
            }
        }

        return 1; // If all conditions are met, return 1 (strings can form a circle)// If all conditions are met, return 1 (strings can form a circle)
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends