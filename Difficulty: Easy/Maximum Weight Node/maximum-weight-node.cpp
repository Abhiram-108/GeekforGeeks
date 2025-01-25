//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maxWeightCell(vector<int> &Edge) {
        int N=Edge.size();
        // code here
       vector<int> weight(N,0);
      for(int i=0;i<N;i++){
          if(Edge[i]!=-1)
            weight[Edge[i]]+=i;
          
      }
      
      int maxV=0;
      int maxNodeCell=0;
      
      for(int i=N-1;i>=0;i--){
          if(maxV<weight[i]){
              maxV=weight[i];
              maxNodeCell=i;
              
          }
          
      }
      
      return maxNodeCell;         
    }
};

//{ Driver Code Starts.
int main() {
    string str;
    getline(cin, str);
    int tc = stoi(str);
    while (tc--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> exits;
        int num;
        while (ss >> num) {
            exits.push_back(num);
        }
        Solution sln;
        cout << sln.maxWeightCell(exits) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends