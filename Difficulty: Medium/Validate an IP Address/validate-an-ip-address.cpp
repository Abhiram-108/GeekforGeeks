//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string s) {
  vector<string> segments;
    string temp;
    stringstream ss(s);
    
    // Split the string by '.'
    while (getline(ss, temp, '.')) {
        segments.push_back(temp);
    }
    
    // Check if the number of segments is 4
    if (segments.size() != 4) {
        return false;
    }
    
    for (string segment : segments) {
        // Check if the segment is empty or has leading zeros
        if (segment.empty() || (segment.size() > 1 && segment[0] == '0')) {
            return false;
        }
        
        // Check if the segment is numeric and within the range 0-255
        int num;
        try {
            num = stoi(segment);
        } catch (...) {
            return false;
        }
        
        if (num < 0 || num > 255) {
            return false;
        }
    }
    
    return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends