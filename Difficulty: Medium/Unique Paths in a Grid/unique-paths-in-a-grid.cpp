class Solution {
    private:
    int help(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i<0||j<0)
        return 0;
        if(grid[i][j]==1)
        return 0;
        if(i==0 && j==0)
        return 1;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        int up=help(grid,i-1,j,dp);
        int left=help(grid,i,j-1,dp);
        return dp[i][j]=left+up;
    }
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(grid,n-1,m-1,dp);
    }
};