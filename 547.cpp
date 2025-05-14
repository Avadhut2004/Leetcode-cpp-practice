// no of provinces 
// tc = O(n)+O(v+2e)
// sc = O(n)+O(n)

class Solution {
private:
    void dfs(int i,vector<int> adjLi[],vector<int>& vis){
        
            vis[i]=1;

            for(auto it:adjLi[i]){
                if(!vis[it]){
                    dfs(it,adjLi,vis);
                }  }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // first converting the adj matrix into an adj list 
        int v = isConnected.size();
        vector<int> adjLi[v];

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLi[i].push_back(j);
                    adjLi[j].push_back(i);
                }
            }
        }


        int cnt=0;
        vector<int> vis(v,0);

        for(int i=0;i<v;i++){
            if (!vis[i]){
                cnt++;
                dfs(i,adjLi,vis);
            }
        }
        return cnt;
    }
};