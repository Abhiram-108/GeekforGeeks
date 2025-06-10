
class Solution {
    int help(vector<int>&prices,vector<vector<int>>&dp,int index,int buy){
        if(index==prices.size())
        return 0;
        if(dp[index][buy]!=-1)
        return dp[index][buy];
        if(buy)
        return dp[index][buy]=max(-prices[index]+help(prices,dp,index+1,0), help(prices,dp,index+1,1));
        
        return dp[index][buy]=max(prices[index]+help(prices,dp,index+1,1), help(prices,dp,index+1,0));
    }
  public:
  
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(prices,dp,0,1);
    }
};
