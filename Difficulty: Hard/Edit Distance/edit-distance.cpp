class Solution {
    int help(int i,int j,vector<vector<int>>&dp,string &s1,string &s2){
        if(i<0)
        return j+1;
        if(j<0)
        return i+1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j])
        return dp[i][j]=0+help(i-1,j-1,dp,s1,s2);
        return dp[i][j]=min(help(i,j-1,dp,s1,s2),min(help(i-1,j,dp,s1,s2),help(i-1,j-1,dp,s1,s2)))+1;
    }
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(m-1,n-1,dp,s1,s2);
    }
};