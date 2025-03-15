// house robber iv 
class Solution {
    public:
        bool canRob(vector<int>& nums, int k, int mid) {
            int count = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    count++;
                    i++; // Skip next house to maintain non-adjacent rule
                }
            }
            return count >= k;
        }
        
        int minCapability(vector<int>& nums, int k) {
            int low = 1, high = *max_element(nums.begin(), nums.end());
            int ans = high;
            
            while (low <= high) {
                int mid = (low + high) / 2;
                if (canRob(nums, k, mid)) {
                    ans = mid;  // Update answer to the lower capability
                    high = mid - 1; // Try for a smaller max value
                } else {
                    low = mid + 1; // Increase the max limit
                }
            }
            return ans;
        }
    };
    