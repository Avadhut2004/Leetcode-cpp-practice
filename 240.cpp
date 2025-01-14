// searching a 2d array pt-ii

// better approach TC=O(n*log(m));
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        for(int i = 0;i<n;i++){
            int low = 0 , high = m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(matrix[i][mid]==target)return true;
                else if(matrix[i][mid]>target) high = mid-1;
                else low = mid+1;
            }
        }
        return false;
    }
};

// optimal approach using elemination 
// TC = O(n+m);SC=O(1);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0 , col = m -1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};