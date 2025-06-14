// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>l(n,1);
        vector<int>r(n,1);
        vector<int>ans(n,1);
        for(int i=1;i<n;i++)
        l[i]=l[i-1]*arr[i-1];
        for(int i=n-2;i>=0;i--)
        r[i]=r[i+1]*arr[i+1];
        for(int i=0;i<n;i++)
        ans[i]=l[i]*r[i];
        
        return ans;
        
        
    }
};
