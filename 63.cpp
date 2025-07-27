// unique paths II 

// memoization

class Solution {
public:
    int func(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return obstacleGrid[0][0]==0? 1:0;
        if(i<0 || j<0)return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int up = func(obstacleGrid,i-1,j,dp);
        int left = func(obstacleGrid,i,j-1,dp);

        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return func(obstacleGrid,n-1,m-1 ,dp);
    }
};

// tabulation method 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        dp[0][0] = obstacleGrid[0][0]==1? 0:1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                int left=0,up=0;

                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];

                dp[i][j]=up+left;
                }
            }
        }
       return dp[n-1][m-1];
    }
};