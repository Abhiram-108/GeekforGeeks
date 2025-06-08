class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        map<int,int>mp;
        int prefixsum=0;
        int ct=0;
        mp[0]=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            prefixsum+=arr[i];
            int remove=prefixsum-0;
           ct+=mp[remove];
           mp[prefixsum]++;
        }
        return ct;
        
    }
};