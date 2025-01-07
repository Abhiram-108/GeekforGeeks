//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int count = 0;
        int left = 0;
        int right = arr.size()-1;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == target){
                count++;
                int l = left+1;
                while(l < right && arr[l] == arr[left]){
                    count++;
                    l++;
                }
                int r = right-1;
                while(left < r && arr[r] == arr[right]){
                    count++;
                    r--;
                }
                left++;
                right--;
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends