// surrounded regions 

class Solution {
private:
    void dfs(vector<vector<char>>& board,int row , int col,vector<vector<int>>&vis,int delrow[] , int delcol[]){
        vis[row][col]=1;
        board[row][col]='z';
        for(int i=0;i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
            dfs(board,nrow,ncol,vis,delrow,delcol);
        }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        // traversing first row and last row 
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(board,0,i,vis,delrow,delcol);
            }

           if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(board,n-1,i,vis,delrow,delcol);
            }
        }

        // traversing first and last col 
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(board,i,0,vis,delrow,delcol);
            }

            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(board,i,m-1,vis,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='z') board[i][j]='O';
                else board[i][j]='X';
            }
        }

    }
};