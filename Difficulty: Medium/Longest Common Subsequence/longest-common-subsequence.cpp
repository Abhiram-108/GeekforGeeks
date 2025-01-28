//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
    int help(int i,int j,int m,int n,string s1,string s2,vector<vector<int>>&dp){
        if(i==m || j==n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int length=0;
        if(s1[i]==s2[j]){
            length=1+help(i+1,j+1,m,n,s1,s2,dp);
        }
        else{
            length=max(help(i+1,j,m,n,s1,s2,dp),help(i,j+1,m,n,s1,s2,dp));
            
        }
        return dp[i][j]=length;
        
    }
  public:
    // Function to find the length of the longest common subsequence in two strings.
    int lcs(string& s1, string& s2) {
        // your code here
        int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends