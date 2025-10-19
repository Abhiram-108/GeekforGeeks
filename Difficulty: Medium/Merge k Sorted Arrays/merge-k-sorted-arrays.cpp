class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        pq.push({mat[i][0], {i,0}});
        
        vector<int>ans;
        
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            
            int el=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            ans.push_back(el);
            
            if(col+1<n){
                pq.push({mat[row][col+1],{row,col+1}});
            }
        }
        return ans;
    }
};