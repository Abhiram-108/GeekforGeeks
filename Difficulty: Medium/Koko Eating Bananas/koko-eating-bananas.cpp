//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
     public:
  
    int findmax(vector<int> &arr){
        int maxi = INT_MIN;
        int n= arr.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi , arr[i]);
        }
        return maxi;
    }
    
    int totaltime(vector<int>& arr , int k){
        int totalh = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            totalh += ceil((double)arr[i]/(double)k);
        }
        return totalh;
    }
    int kokoEat(vector<int>& arr, int k) {
        int low = 1 , high = findmax(arr);
        while(low<=high){
            int mid = (low+high)/2;
            int totalhour = totaltime(arr,mid);
            if(totalhour <=k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
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
        int k = stoi(ks);
        Solution ob;

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends