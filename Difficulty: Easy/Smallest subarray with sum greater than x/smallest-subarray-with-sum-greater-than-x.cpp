class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int l=0,r=0;
        int sum=0;
       int mini=1e9;
        while(r<n){
            sum+=arr[r];
            while(sum>x){
                mini=min(mini,r-l+1);
                sum-=arr[l];
                l++;
                
            }
            r++;
            
            
            
        }
        if(mini==1e9)
        return 0;
        return mini;

    }
};