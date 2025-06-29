// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> destination) {
        // code here
        queue<pair<int,pair<int,int>>>q;
        int m=grid.size();
        int n=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[src.first][src.second]=0;
        q.push({0,{src.first,src.second}});
        
        while(q.size()){
            auto it=q.front();
            q.pop();
            int distance=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==destination.first && y==destination.second)
            return distance;
            
            for(int i=0;i<4;i++){
                int row=x+dr[i];
                int col=y+dc[i];
                if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1 && dist[row][col]>distance+1 ){
                    dist[row][col]=distance+1;
                    if(row==destination.first && col==destination.second){
                        return distance+1;
                    }
                    q.push({distance+1,{row,col}});
                }
            }
            
        }
        return -1;
    }
};
