//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int help(int index,int prev_index,vector<vector<int>>&dp,int n,vector<int>&arr){
        if(index==n )
        return 0;
        if(dp[index][prev_index+1]!=-1)
        return dp[index][prev_index+1];
        int nottake=help(index+1,prev_index,dp,n,arr);
        int take=0;
        if(prev_index==-1 || arr[index]>arr[prev_index])
        take=arr[index]+help(index+1,index,dp,n,arr);
        return dp[index][prev_index+1]=max(take,nottake);
      
        
        
    }
  public:
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return help(0,-1,dp,n,arr);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends