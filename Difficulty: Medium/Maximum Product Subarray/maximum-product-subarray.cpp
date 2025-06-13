class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=1;
        int r=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            l*=arr[i];
            r*=arr[n-i-1];
            maxi=max(max(l,r),maxi);
            if(l==0)
            l=1;
            if(r==0)
            r=1;
            
            
        }
        return maxi;
    }
};