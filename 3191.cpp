class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int ops = 0;
            
            for (int i = 0; i <= n - 3; i++) {
                if (nums[i] == 0) {  // We must flip this triplet
                    ops++;
                    nums[i] ^= 1;
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                }
            }
            
            // Check if any 0s remain in the last two elements (cannot be flipped)
            for (int i = n - 2; i < n; i++) {
                if (nums[i] == 0) return -1;
            }
            
            return ops;
        }
    };
    