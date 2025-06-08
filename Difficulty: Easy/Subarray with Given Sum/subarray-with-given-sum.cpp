// User function Template for C++
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>& a, int target) {
        if(target==0)
        return {};
        int n=a.size();
        int sum=0;
        int l=0;
        int r=0;
        while(r<n){
            sum+=a[r];
            while(sum>target){
                sum-=a[l];
                l++;
            }
            if(sum==target){
                return {l+1,r+1};
            }
            r++;
        }
        return {};
    }
};