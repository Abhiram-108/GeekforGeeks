class Solution {
    
    void merge(vector<int>&arr, int low, int mid,int high){
        int left=low;
        int right=mid+1;
        
        vector<int>temp;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        
    }
    
    int inversions(vector<int>&arr,int low,int mid, int high){
        
        int ct=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && arr[i]>arr[right]){
                right++;
            }
            ct+=(right-(mid+1));
        }
        
        return ct;
        
    }
    
    int mergesort(vector<int>&arr, int low, int high){
        
        
        if(low>=high)
        return 0;
        
        int ct=0;
        int mid=(low+high)/2;
        ct+=mergesort(arr,low,mid);
        ct+=mergesort(arr,mid+1,high);
        ct+=inversions(arr,low,mid,high);
        
        merge(arr,low,mid,high);
        
        return ct;
        
        
        
        
    }
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        
        
        int n=arr.size();
        
        return mergesort(arr,0,n-1);
        
    }
};