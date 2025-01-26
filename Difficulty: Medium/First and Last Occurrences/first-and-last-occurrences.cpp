//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        vector<int>ans(2,-1);
        int l=0;
        int r=n-1;
        while(l<r){
            if(arr[l]!=x)
            l++;
            if(arr[r]!=x)
            r--;
            if(arr[l]==x && arr[r]==x)
            {
                ans[0]=l;
                ans[1]=r;
                break;
            }
            
        }
        return ans;
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
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends