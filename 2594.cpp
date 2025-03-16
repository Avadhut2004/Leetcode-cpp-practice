// minimum time to repair cars 
class Solution {
    public:
        bool canRepairAll(vector<int>& ranks, int cars, long long mid) {
            long long repaired = 0;
            for (int r : ranks) {
                long long k = sqrt(mid / r); // Max cars this mechanic can repair in 'mid' time
                repaired += k;
                if (repaired >= cars) return true;
            }
            return repaired >= cars;
        }
    
        long long repairCars(vector<int>& ranks, int cars) {
            long long low = 1, high = (long long) *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
            long long ans = high;
    
            while (low <= high) {
                long long mid = (low + high) / 2;
                if (canRepairAll(ranks, cars, mid)) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        }
    };
sdf    