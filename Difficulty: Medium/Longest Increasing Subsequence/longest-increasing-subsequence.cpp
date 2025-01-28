//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    private:
    int f(int index,int prev_index,vector<int>&nums,vector<vector<int>>&dp,int n){
      if(index==n)
        return 0;
        if(dp[index][prev_index+1]!=-1)
        return dp[index][prev_index+1];
        int len=0+f(index+1,prev_index,nums,dp,n);
        if(prev_index==-1 || nums[index]>nums[prev_index])
        len=max(len,1+f(index+1,index,nums,dp,n));
        return dp[index][prev_index+1]=len;
    }
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& nums) {
        // code here
         int  n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return f(0,-1,nums,dp,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends