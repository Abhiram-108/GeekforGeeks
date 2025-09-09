class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        map<int,int>mp;
        int sum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0)
            maxi=i+1;
            else{
                if(mp.find(sum)!=mp.end())
                maxi=max(maxi,i-mp[sum]);
                else
                mp[sum]=i;
            }
        }
        return maxi;
    }
};