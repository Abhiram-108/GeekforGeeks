class Solution {
    void dfs(int node,int dest,vector<int>adj[],int &ct,vector<int>&vis){
        if(node==dest)
        {
            ct++;
            return;
        }
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,dest,adj,ct,vis);
            }
            vis[it]=0;
        }
        
        
    }
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int v, vector<int> adj[], int source, int destination) {
        // Code here
        vector<int>vis(v,0);
        int ct=0;
        for(int i=0;i<v;i++){
            if(i==source){
                vis[i]=1;
            dfs(i,destination,adj,ct,vis);
            }
            
        }
        return ct;
            
        
    }
};