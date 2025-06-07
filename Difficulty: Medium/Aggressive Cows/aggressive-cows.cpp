// User function Template for C++

class Solution {
    private:
    bool canplace(vector<int>&arr,int dis,int k){
        int first=arr[0];
        int cntcows=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-first>=dis){
            cntcows++;
            first=arr[i];}
        }
        if(cntcows>=k)
        return true;
        else
        return false;
    }
  public:

    int aggressiveCows(vector<int> &arr, int k) {

        // Write your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int l=1;
        int r=arr[n-1]-arr[0];
        while(l<=r){
            int mid=(l+r)/2;
            if(canplace(arr,mid,k)){
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return l-1;
    }
};