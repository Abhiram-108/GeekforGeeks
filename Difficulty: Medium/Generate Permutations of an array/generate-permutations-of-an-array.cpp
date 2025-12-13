class Solution {
    void help(vector<vector<int>>&ans,vector<int>&arr,int index){
        if(index>=arr.size()){
            ans.push_back(arr);
            return;
        }
        
        for(int i=index;i<arr.size();i++){
            swap(arr[index],arr[i]);
            help(ans,arr,index+1);
            swap(arr[index],arr[i]);
        }
        
        return;
    }
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        
      
        help(ans,arr,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};