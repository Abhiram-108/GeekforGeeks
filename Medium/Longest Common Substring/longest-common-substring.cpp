//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string x, string y, int m, int n)
    {
        // your code here
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++)
            dp[i][j]=0;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(x[i]==y[j])
                dp[i+1][j+1]=1+dp[i][j];
                else
                dp[i+1][j+1]=0;
            }
        }
        int x1=0;
        for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            x1=max(x1,dp[i][j]);
            
            
        }}
        return  x1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends