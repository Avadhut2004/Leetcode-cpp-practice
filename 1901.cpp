// find peak element in a 2d array 
// optimal approach using binary search 
// TC = O(m*logm);
// sc = 1

class Solution {
public:

    int maxeleindex(vector<vector<int>>& mat,int n, int col){
        int maxel = -1 , index = -1;
        for(int i =0;i<n;i++){
            if(mat[i][col]>maxel){
                maxel = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size() , m = mat[0].size();
        int low = 0 , high = m-1;

        while(low <= high){
            int mid = (low+high)/2;

            int maxeleind = maxeleindex(mat,n,mid);
            int left = (mid-1)>0? mat[maxeleind][mid-1]:-1;
            int right = (mid+1)<m? mat[maxeleind][mid+1]:-1;

            if(mat[maxeleind][mid]>left && mat[maxeleind][mid]>right ) return {maxeleind,mid};
            else if(mat[maxeleind][mid]<left ) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};