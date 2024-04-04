//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
          const unsigned int M = 1000000007;
        long long result=0;
        vector<long long >ans(s.length());
        for(int i=0;i<s.length();i++){
            if(i==0){
                ans[i]=((i+1)*(s[i]-'0'))%M;
            }
            else{
                ans[i]=((i+1)*(s[i]-'0')+10*ans[i-1])%M;
            }
            result+=(ans[i])%M;
        }
       
        return result%M;
        
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
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends