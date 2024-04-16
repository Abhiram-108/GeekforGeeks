//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int f(int wt,int w[],int val[],vector<vector<int>>&dp,int index){
        if(index==0){
            if(w[index]<=wt)
            return val[index];
            else
            return 0;
            
        }
        if(dp[index][wt]!=-1)
        return dp[index][wt];
        int nottake=0+f(wt,w,val,dp,index-1);
        int take=INT_MIN;
        if(w[index]<=wt)
        take=val[index]+f(wt-w[index],w,val,dp,index-1);
        return dp[index][wt]=max(nottake,take);
        
    }
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int wt, int w[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(wt+1,-1));
       return f(wt,w,val,dp,n-1);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends