//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int count=0;
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=diff;j<n;i++,j++){
                if(diff==0){
                    dp[i][j]=1;
                }
               else if(diff==1){
                    if(s[i]==s[j])
                    dp[i][j]=1;
                    else
                    dp[i][j]=0;
                }
                else {
                    if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                    else
                    dp[i][j]=0;
                }
                if(dp[i][j]==1 && diff>=1)
                count++;
                
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends