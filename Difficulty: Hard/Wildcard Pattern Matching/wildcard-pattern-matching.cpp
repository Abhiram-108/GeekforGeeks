//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int help(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i<0 && j<0)
        return true;
        if(i<0 && j>=0)
        return false;
        if(j<0 && i>=0){
            for(int x=0;x<=i;x++){
                if(s1[x]!='*')
                return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        //match condition
        if(s1[i]==s2[j] || s1[i]=='?'){
        return dp[i][j]=help(i-1,j-1,s1,s2,dp);}
        if(s1[i]=='*'){
        return dp[i][j]=help(i-1,j,s1,s2,dp)|help(i,j-1,s1,s2,dp);}
        return dp[i][j]=false;
    }
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        int m=pattern.size();
        int n=str.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(m-1,n-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends