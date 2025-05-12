// combination sum II 

class Solution {
    public:
        void combi(int ind,int target , vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
            if(target == 0){
                ans.push_back(ds);
                return;
            }
    
            // looping
    
            for(int i = ind;i<arr.size();i++){
                if(i>ind && arr[i]==arr[i-1]) continue;
    
                if(arr[i]>target) break;
    
                ds.push_back(arr[i]);
                combi(i+1,target-arr[i],arr,ans,ds);
                // backtrack
    
                ds.pop_back();
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<vector<int>>ans;
            vector<int>ds;
    
            combi(0,target,candidates,ans,ds);
            return ans;}
    };