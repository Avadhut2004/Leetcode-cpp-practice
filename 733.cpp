// flood fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int original = image[sr][sc];
        queue<pair<int,int>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        q.push({sr,sc});
        image[sr][sc]=color;
        vis[sr][sc]=1;

        // for finding neighbors
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol =c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==original && vis[nrow][ncol]!=1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
            }
        }

        return image;
    }
};