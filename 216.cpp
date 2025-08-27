class Solution {
public:
    vector<vector<int>>res;

    void backtrack(int start , vector<int>&path,int k ,int n,int sum){
        // base case 
        if(sum==n && path.size()==k){
            res.push_back(path);
            return;
        }

        if(sum>n || path.size()>k)return;

        for(int i=start;i<=9;i++){
            path.push_back(i);

            backtrack(i+1,path,k,n,sum+i);

            // backtrack
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        backtrack(1,path,k,n,0);

        return res;
    }
};
