//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
         int dif = INT_MAX , ans = INT_MIN;
        sort(arr.begin() , arr.end());
        for(int i = 0 ; i < arr.size() ;i++){
            int start = i+1;
            int end = arr.size() - 1;
            while(start < end){
                int sum = arr[i] + arr[start] + arr[end];
                if(sum == target) return sum;
                else if(sum > target) end--;
                else start++;
                if(abs(sum - target) < dif){
                    dif = abs(sum - target);
                    ans = sum;
                }
                else if(abs(sum - target) == dif){
                    ans = max(ans , sum);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends