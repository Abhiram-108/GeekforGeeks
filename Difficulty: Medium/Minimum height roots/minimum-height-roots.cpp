class Solution {
  public:
    vector<int> minHeightRoot(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>indegree(n,0);
        
       for(int i=0;i<n;i++){
           for(auto it:adj[i]){
               indegree[it]++;
           }
       }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==1)
            q.push(i);
        }
        
        int remain=n;
        while(remain>2){
            int size=q.size();
            
            remain-=size;
            
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1)
                    q.push(it);
                    
                }
            }
        }
        
        vector<int>ans;
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};