//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& a, int k) {
        // code here
        deque<int>dq;
        vector<int>ans;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(dq.size() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(dq.size() && a[dq.back()]<=a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
            ans.push_back(a[dq.front()]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends