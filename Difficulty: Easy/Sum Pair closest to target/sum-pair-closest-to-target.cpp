//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l=0;
        int r=n-1;
        int diff=INT_MAX;
        while(l<r){
            int x=arr[l]+arr[r];
            if(abs(x-target)<diff){
                diff=abs(x-target);
                ans={arr[l],arr[r]};
            }
            if(x<target)
            l++;
            else if(x>target)
            r--;
            else if(x==target)
            return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends