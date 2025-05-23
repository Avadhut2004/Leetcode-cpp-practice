// shortest path in a grid 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If starting or ending point is blocked
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 1; // starting cell counts as 1 step
        q.push({1, {0, 0}});

        int drow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dcol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while(!q.empty()) {
            auto it = q.front(); q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == n-1) return dis;

            for(int i = 0; i < 8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && 
                   grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};
