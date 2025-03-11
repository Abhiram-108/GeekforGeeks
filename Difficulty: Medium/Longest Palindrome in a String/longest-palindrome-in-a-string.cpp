//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";
    
    int maxi = 0;
    string ans = "";
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int diff = 0; diff < n; diff++) {
        for (int i = 0, j = diff; j < n; i++, j++) {
            if (diff == 0) {
                dp[i][j] = 1;  // Single character is always a palindrome
            } 
            else if (diff == 1) {
                dp[i][j] = (s[i] == s[j]); // Two characters are palindrome if they are equal
            } 
            else {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1; // Extend inner palindrome
                } else {
                    dp[i][j] = 0;
                }
            }

            if (dp[i][j] == 1) {
                int temp = j - i + 1;
                if (temp > maxi) {
                    maxi = temp;
                    ans = s.substr(i, temp);  // Fix: Use substr(start, length)
                }
            }
        }
    }
        // cout<<maxi<<endl;
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends