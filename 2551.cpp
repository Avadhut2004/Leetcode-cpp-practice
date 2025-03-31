// Put marbles in bag 

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
            if (k == 1) return 0;  // No partitions, score difference is 0
            
            vector<long long> pairSums;
            
            // Compute adjacent pair sums
            for (int i = 0; i < n - 1; i++) {
                pairSums.push_back(weights[i] + weights[i + 1]);
            }
            
            // Sort the pair sums
            sort(pairSums.begin(), pairSums.end());
    
            long long minScore = 0, maxScore = 0;
    
            // Compute min and max scores using `k-1` values
            for (int i = 0; i < k - 1; i++) {
                minScore += pairSums[i];                          // Smallest sums for min score
                maxScore += pairSums[n - 2 - i];                 // Largest sums for max score
            }
            
            return maxScore - minScore;
        }
    };
    