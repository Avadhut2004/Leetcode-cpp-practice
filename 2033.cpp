// minimum operations to make a uni-value grid

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> arr;
            int m = grid.size(), n = grid[0].size();
            
            // Flatten the grid into a 1D array
            for (auto& row : grid) {
                for (int val : row) {
                    arr.push_back(val);
                }
            }
    
            // Sort the array to find the median
            sort(arr.begin(), arr.end());
    
            // Check if transformation is possible
            int median = arr[arr.size() / 2];
            int operations = 0;
    
            for (int val : arr) {
                int diff = abs(val - median);
                if (diff % x != 0) return -1; // If not divisible, return impossible
                operations += diff / x; // Count number of operations
            }
    
            return operations;
        }
    };
    