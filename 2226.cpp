// maximum candies allocated to k children 
//  tc = o(n log(max(candies)))

class Solution {
    public:
        bool checktotal(vector<int>& candies, int mid, long long k) {
            long long count = 0;
            for (int candy : candies) {
                count += candy / mid;
            }
            return count >= k; 
        }
    
        int maximumCandies(vector<int>& candies, long long k) {
            int high = *max_element(candies.begin(), candies.end());
            int low = 1;
            int ans = 0;
    
            // Handle edge case where total candies are less than k
            if (accumulate(candies.begin(), candies.end(), 0LL) < k) return 0;
    
            while (low <= high) {
                int mid = low + (high - low) / 2; // Avoid overflow
                if (checktotal(candies, mid, k)) {
                    ans = mid; // Store valid answer
                    low = mid + 1; // Try a larger mid
                } else {
                    high = mid - 1; 
                }
            }
            return ans;
        }
    };
    