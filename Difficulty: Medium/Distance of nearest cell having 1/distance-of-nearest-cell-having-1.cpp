class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(q.size()){
             int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dis[row][col]=steps;
            for(int i=0;i<4;i++){
              int  newr=row+dr[i];
                int newc=col+dc[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]==0){
                    vis[newr][newc]=1;
                    q.push({{newr,newc},steps+1});
                }
            }
            
        }
        return dis;
        
    }
};