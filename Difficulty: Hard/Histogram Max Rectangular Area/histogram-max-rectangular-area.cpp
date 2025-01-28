//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int help(vector<int>&arr,int maxarea){
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(st.size() && arr[i]<=arr[st.top()]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1:st.top();
                maxarea=max(maxarea,((arr[element])*(nse-pse-1)));
                
            }
            st.push(i);
        }
        while(st.size()){
            int nse=arr.size();
            int element=st.top();
            st.pop();
            int pse=st.empty() ?-1:st.top();
               maxarea=max(maxarea,((arr[element])*(nse-pse-1)));
               
        }
        return maxarea;
    }
  public:
    // Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int maxarea=0;
        maxarea=help(arr,maxarea);
        return maxarea;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends