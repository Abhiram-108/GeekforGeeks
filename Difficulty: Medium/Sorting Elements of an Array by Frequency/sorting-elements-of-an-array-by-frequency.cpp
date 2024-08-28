//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& nums) {
        // Your code here
        //elements will have higher frequency will com first
       unordered_map<int, int> map;
        for (auto i : nums) {
            map[i]++;
        }
        sort(nums.begin(), nums.end(), [&map](int a, int b) {
            if (map[a] == map[b]) {
                return a < b;
            }
            return map[a] > map[b];
        });
        return nums;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends