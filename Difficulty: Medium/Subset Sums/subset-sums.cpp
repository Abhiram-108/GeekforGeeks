//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void help(int index,vector<int>&ans,vector<int>&arr,int n,int sum){
        if(index==n){
        ans.push_back(sum);
            return;
        }
        help(index+1,ans,arr,n,sum+arr[index]);
        help(index+1,ans,arr,n,sum);
        return;
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
       int n=arr.size();
       vector<int>ans;
       help(0,ans,arr,n,0);
       sort(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends