//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int f(int wt,vector<int>&w,vector<int>&val,vector<vector<int>>&dp,int index){
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
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int wt, vector<int>& w, vector<int>& val) {
        // Your code here
    
       // Your code here
       int n=w.size();
       vector<vector<int>>dp(n,vector<int>(wt+1,-1));
       return f(wt,w,val,dp,n-1);
    
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends