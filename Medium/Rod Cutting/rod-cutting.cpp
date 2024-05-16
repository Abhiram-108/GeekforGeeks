//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int d(vector<vector<int>>&dp,int price[],int index,int n){
        if(index==0)
        return n*price[index];
        if(dp[index][n]!=-1)
        return dp[index][n];
        int nottake=0+d(dp,price,index-1,n);
        int take=INT_MIN;
        int rodlength=index+1;
        if(rodlength<=n)
        take=price[index]+d(dp,price,index,n-rodlength);
        return dp[index][n]=max(take,nottake);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return d(dp,price,n-1,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends