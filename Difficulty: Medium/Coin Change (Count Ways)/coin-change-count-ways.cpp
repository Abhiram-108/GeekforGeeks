//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int help(vector<int>&a,int target,vector<vector<int>>&dp,int index){
        if(index==0){
            if(target % a[index]==0)
            return 1;
            return 0;
        }
        if(dp[index][target]!=-1)
        return dp[index][target];
        int nottake=help(a,target,dp,index-1);
        int take=0;
        if(a[index]<=target)
        take=help(a,target-a[index],dp,index);
        return dp[index][target]=take+nottake;
    }
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return help(coins,sum,dp,n-1);
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends