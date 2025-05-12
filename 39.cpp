// combination sum 

class Solution {
    public:
       void combi(int ind , int target , vector<int>& arr ,vector<vector<int>>& ans ,vector<int>& ds ){
            if(ind>=arr.size()){
                if(target==0){
                    ans.push_back(ds);
                }
                return ;
            }
    
            // include 
            if(arr[ind]<= target){
                ds.push_back(arr[ind]);
                combi(ind,target-arr[ind],arr,ans,ds);
    
                // backtrack
                ds.pop_back();
            }
    
            // exclude 
    
            combi(ind+1,target,arr,ans,ds);
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>>ans;
            vector<int>ds;
    
           combi(0,target,candidates,ans,ds);
           return ans;
        }
    };