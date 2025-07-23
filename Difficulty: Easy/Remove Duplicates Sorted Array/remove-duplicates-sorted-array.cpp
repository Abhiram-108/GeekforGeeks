class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        int j=1;
        int ct=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                ct++;
            }
            else ct=1;
            if(ct==1){
                arr[j]=arr[i];
                j++;
                
                
                
            }
        }
        int n=arr.size();
        while(n!=j){
            arr.pop_back();
            n--;
        }
        return arr;
    }
};