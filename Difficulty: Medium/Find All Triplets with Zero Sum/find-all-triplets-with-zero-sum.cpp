//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
 
        // Code here
           vector<vector<int>> findTriplets(vector<int> &arr) {
        // Stores the resulting triplets
        vector<vector<int>> ans;

        // Hash map to store values and their indices
        unordered_map<int, vector<int>> mp;
        
        // Populate the hash map with elements and their indices
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }
        
        // Traverse each pair of elements in the array
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                int sum = arr[i] + arr[j];         // Calculate pair sum
                int req = -sum;                   // Required third element
                
                // Check if the required element exists in the map
                if (mp.find(req) != mp.end()) {
                    // For each occurrence of the required element, check constraints
                    for (int k : mp[req]) {
                        if (k != i && k != j && i < j && j < k) {
                            // Add the triplet if valid
                            ans.push_back({i, j, k});
                        }
                    }
                }
            }
        }
        
        return ans; // Return all valid triplets
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends