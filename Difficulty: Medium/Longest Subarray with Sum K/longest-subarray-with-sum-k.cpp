class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
       map<int,int>mp;
       int prefSum=0;
       int res=0;
         for (int i = 0; i < arr.size(); ++i) {
        prefSum += arr[i];

        // Check if the entire prefix sums to k
        if (prefSum == k) 
            res = i + 1;

        // If prefixSum - k exists in the map then there exist such 
      	// subarray from (index of previous prefix + 1) to i.
        else if (mp.find(prefSum - k) != mp.end()) 
            res = max(res, i - mp[prefSum - k]);

        // Store only first occurrence index of prefSum
      	if (mp.find(prefSum) == mp.end())
            mp[prefSum] = i;
    }
    return res;
    }
};