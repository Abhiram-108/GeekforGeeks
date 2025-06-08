class Solution {
  public:
    long long findMaxSubarraySum(vector<int>& a, long long x) {
        // Your code goes here
        long long maxi=0;
        int n=a.size();
        int r=0,l=0;
        long long sum=0;
        while(r<n){
            sum+=a[r];
            while(sum>x){
                sum-=a[l];
                l++;
            }
            maxi=max(sum,maxi);
            r++;
        }
        return maxi;
         
    }
};
