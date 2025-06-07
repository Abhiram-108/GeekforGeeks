// User function Template for C++

class Solution {
    private:
    int help(int capacity,int arr[],int n,int d){
        int t=0;
        int days=1;
        for(int i=0;i<n;i++){
            t+=arr[i];
            if(t>capacity){
                t=arr[i];
                days++;
                
            }
        }
        return days;
    }
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
            
        }
        int l=maxi;
        int r=sum;
        while(l<=r){
            int mid=(l+r)/2;
            if(help(mid,arr,n,d)<=d){
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return l;
    }
};