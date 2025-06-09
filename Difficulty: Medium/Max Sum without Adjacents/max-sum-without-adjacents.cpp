// User function template for C++
class Solution {
    int help(vector<int>&dp,vector<int>&a,int index){
        if(index<0)
        return 0;
        if(index==0)
        return a[index];
        if(dp[index]!=-1)
        return dp[index];
        int nottake=help(dp,a,index-1);
        int take=a[index]+help(dp,a,index-2);
        return dp[index]=max(take,nottake);
    }
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>&a) {
        // code here
        int n=a.size();
        vector<int>dp(n,-1);
        return help(dp,a,n-1);
    }
};