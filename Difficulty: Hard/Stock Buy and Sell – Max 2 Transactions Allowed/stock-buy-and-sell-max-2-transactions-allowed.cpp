class Solution {
    
    int help(vector<vector<vector<int>>>&dp,vector<int>&prices,int index,int buy,int cap){
        if (index==prices.size())
        return 0;
        if(cap==0)
        return 0;
        if(dp[index][buy][cap]!=-1)
        return dp[index][buy][cap];
        
        
        if(buy)
        return dp[index][buy][cap]=max(-prices[index]+help(dp,prices,index+1,0,cap), help(dp,prices,index+1,1,cap));
        
        return dp[index][buy][cap]=max(prices[index]+help(dp,prices,index+1,1,cap-1), help(dp,prices,index+1,0,cap));
    }
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        
        return help(dp,prices,0,1,2);
    }
};