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