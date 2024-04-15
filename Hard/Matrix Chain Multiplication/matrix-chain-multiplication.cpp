//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++





class Solution{
        private:
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++){
            int burst=nums[i-1]*nums[k]*nums[j]+f(i,k,nums,dp)+f(k+1,j,nums,dp);
            mini=min(mini,burst);
        }
        return dp[i][j]=mini;
    }
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<int>nums(n);
        for(int i=0;i<n;i++)
        nums[i]=arr[i];

        vector<vector<int>>dp((n),vector<int>(n,-1));
        return f(1,n-1,nums,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends