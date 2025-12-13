class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int ct=0;
        int prefixsum=0;
        for(int i=0;i<n;i++){
            prefixsum+=arr[i];
            int rem=prefixsum-target;
            if(mp[rem])
            ct+=mp[rem];
            mp[prefixsum]++;
        }
        return ct;
        
    }
};