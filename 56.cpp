// merge intervals 
// tc = sc = o(N)

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>>ans;
         vector<int>tempinterval;
    
         sort(intervals.begin(),intervals.end());
    
         tempinterval = intervals[0];
    
         for(auto it:intervals){
            if(it[0]<=tempinterval[1]){
                tempinterval[1] = max(tempinterval[1],it[1]);
            }
            else{
                ans.push_back(tempinterval);
                tempinterval = it;
            }
            
         }  
         ans.push_back(tempinterval);
         return ans;
        }
    };