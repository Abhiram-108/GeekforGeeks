//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
    bool  dfscheck(int node,vector<int>adj[],int vis[],int pathvis[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it: adj[node]){
            //when node is not visited
            if(!vis[it]){
                if(dfscheck(it,adj,vis,pathvis)==true)
                return true;
            }
             //if node is already visited but iis to be on same path
            else if(pathvis[it])
            return true;
            
        }
         pathvis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        int vis[v]={0};
        int pathvis[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i]){
               if( dfscheck(i,adj,vis,pathvis)==true)
               return true;
                
            }
            //if node is already visited but iis to be on same path
           
            
        }
        return false;
          
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends