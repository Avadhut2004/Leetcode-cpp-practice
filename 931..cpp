// minimum falling path sum 

// memoization approach (TC,sc = O(n*m),O(n*m)+O(n))

class Solution {
public:

    int fallingPath( vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp){
        if(j<0 || j>= matrix[0].size()) return 1e9;
        if(i==0) return matrix[i][j];

        if(dp[i][j]!=-1)return dp[i][j];
        
        int up = matrix[i][j]+fallingPath(matrix,i-1,j,dp);
        int upRight = matrix[i][j]+fallingPath(matrix,i-1,j+1,dp);
        int upLeft = matrix[i][j]+fallingPath(matrix,i-1,j-1,dp);

        return dp[i][j]= min({up,upRight,upLeft});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int minPathSum = 1e9;

        for(int i=0;i<n;i++){
            minPathSum = min(minPathSum , fallingPath(matrix,n-1,i,dp));
        }
        return minPathSum;
    }
};

// tabulation (SC = O(n*m)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int minPathSum = 1e9;

        for(int i=0;i<m;i++){
            dp[0][i]= matrix[0][i];
            }

            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                    int up = 1e9,upleft =1e9,upright=1e9;

                    up = matrix[i][j]+dp[i-1][j];

                   
                    if(j>0)    upleft = matrix[i][j]+dp[i-1][j-1];
                    if(j<m-1)   upright =matrix[i][j] + dp[i-1][j+1];
                    

                    dp[i][j]=min({up,upleft,upright});
                }
            }
        
        for(int i=0;i<n;i++){
            minPathSum = min(minPathSum , dp[n-1][i]);
        }
        
        return minPathSum;
    }
};