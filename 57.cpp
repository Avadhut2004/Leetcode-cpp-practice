// insert interval 
//  tc = sc = o(n)

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            int i = 0 ;
            int len = intervals.size();
            vector<vector<int>>res;
    
            while(i<len && intervals[i][1]<newInterval[0]){
                //  left part 
                res.push_back(intervals[i]);
                i = i+1;
            }
    
            while(i<len && intervals[i][0]<=newInterval[1]){
                //  middle overlapping part 
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
                i = i+1;
            }
            res.push_back(newInterval);
    
            while(i<len){
                // right part 
    
                res.push_back(intervals[i]);
                i=i+1;
            }
    
            return res;
        }
    };