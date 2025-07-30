// minsum path for a triangular grid 
// memoization approach
class Solution {
public:
    int triangleMin(vector<vector<int>>&triangle , vector<vector<int>>&dp,int i,int j){
        int n = triangle.size();
        if(i==n-1)return triangle[i][j];
        if(j<0 || i<0 || j>=triangle[i].size()) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int downDiagonal = triangle[i][j]+triangleMin(triangle,dp,i+1,j+1);
        int down = triangle[i][j]+triangleMin(triangle,dp,i+1,j);

        return dp[i][j] = min(down,downDiagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return triangleMin(triangle,dp,0,0);
    }
};

// tabulation approach

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Create a dp array same as triangle's bottom row
        vector<int> dp(triangle[n-1]);

        // Build from second-last row upwards
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        // The top cell will have the result
        return dp[0];
    }
};
