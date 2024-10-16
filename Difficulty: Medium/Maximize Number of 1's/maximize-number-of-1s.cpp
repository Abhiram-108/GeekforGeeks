//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int nums[], int n, int m) {
       
        // code here
        int l=0,r=0,len=0,ans=0,ct=0;
        while(r<n){
            if(nums[r]==0)
            ct++;
            if(ct>m){
                if(nums[l]==0) ct--;
                l++;
            }
            if(ct<=m)
            len=r-l+1;
            ans=max(ans,len);
            r++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends