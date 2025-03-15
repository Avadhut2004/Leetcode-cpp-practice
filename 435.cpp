// non overlapping intervals 

class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            if (intervals.empty()) return 0;
            
            // Step 1: Sort intervals by their end time
            sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1]; 
            });
    
            int count = 0;  // Count of intervals to be removed
            int prevEnd = intervals[0][1]; // End of the first interval
    
            // Step 2: Iterate through the sorted intervals
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] < prevEnd) {
                    // Overlapping interval, remove it
                    count++;
                } else {
                    // No overlap, update end time
                    prevEnd = intervals[i][1];
                }
            }
            return count;
        }
    };
    