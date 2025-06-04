class Solution {


private:
int isvalid(int i,int j,int n){
     return i>=0 && i<n && j>=0 && j<n;
}

public:
    int minimumCostPath(vector<vector<int>>& grid) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=grid.size();
        
        vector<vector<int>>cost(n,vector<int>(n,1e9));
        cost[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
         vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
         while(pq.size()){
             vector<int>top=pq.top();
             pq.pop();
             int x=top[1];
             int y=top[2];
             for(auto it:dir){
                 int i=x+it[0];
                 int j=y+it[1];
                 if(isvalid(i,j,n)){
                     if(cost[x][y]+grid[i][j]<cost[i][j])
                     {
                         cost[i][j]=grid[i][j]+cost[x][y];
                         pq.push({cost[i][j],i,j});
                     }
                 }
             }
         }
        
        return cost[n-1][n-1];
       
    }
};
