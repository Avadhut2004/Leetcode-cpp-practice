// number of enclaves 

class Solution {
private:
    void dfs(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&vis){
        vis[row][col]=1;
        grid[row][col]=4;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(grid,nrow,ncol,vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis(n,vector<int>(m,0));
        // traversing first and last row 
      for(int i=0;i<m;i++){
        if(!vis[0][i] && grid[0][i]==1){
            
            dfs(grid,0,i,vis);
        }

        if(!vis[n-1][i] && grid[n-1][i]==1){
            
            dfs(grid,n-1,i,vis);
        }
      }  

// traversing first and last col 
      for(int i=0;i<n;i++){
        if(!vis[i][0] && grid[i][0]==1){
            
            dfs(grid,i,0,vis);
        }

        if(!vis[i][m-1] && grid[i][m-1]==1){
            
            dfs(grid,i,m-1,vis);
        }
      } 
    int cnt=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) cnt++;
        }
      } 
      return cnt;
    }
};