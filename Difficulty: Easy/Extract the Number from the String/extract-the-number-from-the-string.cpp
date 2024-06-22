//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {
        long long ans=0,temp=0;
        bool indication=false;
        for(auto it:s){
            if(it-'0'>=0 and it-'0'<=9){
                temp=temp*10+(it-'0');
                if(it=='9')
                indication=true;
            }
            if(it==' '){
                if(!indication)
                    ans=max(ans,temp);
                    temp=0;
                    indication=false;
            
                
            }
            
        }
        if(!indication)
        ans=max(ans,temp);
        if(ans)
        return ans;
        return -1;

        // code here
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends