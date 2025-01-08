//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int count=0;
        for(int k=arr.size()-1;k>=2;k--){
            int st=0;
            int ed=k-1;
            while(ed>st){
                int sum=arr[st]+arr[ed];
                if(sum>arr[k]){
                    count+=ed-st;
                    ed--;
                }
                else{
                    st++;
                }
            }
        }
            return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends