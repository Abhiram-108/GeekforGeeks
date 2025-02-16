//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  private:
    int help(vector<vector<int>>& dp, vector<int>& a, int target, int index) {
        // Base Case
        if (target == 0) return 1; // If target becomes 0, subset exists
        if (index == 0) return (a[0] == target); // Only one element to check

        // Memoization check
        if (dp[index][target] != -1) return dp[index][target];

        // Exclude the current element
        int notTake = help(dp, a, target, index - 1);

        // Include the current element (if it doesn't exceed target)
        int take = 0;
        if (target >= a[index])
            take = help(dp, a, target - a[index], index - 1);

        return dp[index][target] = (take || notTake);
    }

  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return help(dp, arr, target, n - 1);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends