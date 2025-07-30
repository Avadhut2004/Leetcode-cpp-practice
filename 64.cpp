// min path grid 
// memoization approach 

class Solution {
public:
    int minsum(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j){
        if(i==0 && j==0)return grid[0][0];
        if(i<0||j<0) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = grid[i][j]+ minsum(grid,dp,i-1,j);
        int left = grid[i][j]+minsum(grid , dp , i , j-1);

        return dp[i][j]=min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return minsum(grid,dp,n-1,m-1);


    }
};

// tabulation approach 

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        dp[0][0]=grid[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue ;

                int up =   1e9;
                int left = 1e9;
                if(i>0) up = grid[i][j]+dp[i-1][j];
                if(j>0) left = grid[i][j]+dp[i][j-1];

                dp[i][j]=min(up,left);
            }
        }
     return dp[n-1][m-1];

    }
};