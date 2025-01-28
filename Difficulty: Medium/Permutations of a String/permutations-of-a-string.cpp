//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
   void help(set<string>&a,int index,string s){
        if(index==s.size()){
            a.insert(s);
            return;
        }
        for(int i=index;i<s.size();i++){
            swap(s[index],s[i]);
            help(a,index+1,s);
            swap(s[index],s[i]);
        }
        return;
    }
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        int n=s.size();
        set<string>a;
        help(a,0,s);
        vector<string>ans;
        for(auto it:a){
            ans.push_back(it);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends