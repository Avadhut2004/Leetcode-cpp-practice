// longest nice subarray 

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int left = 0, right = 0, currOR = 0, maxLen = 0;
            
            while (right < nums.size()) {
                while ((currOR & nums[right]) != 0) {
                    currOR ^= nums[left];
                    left++;
                }
                currOR |= nums[right];
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            
            return maxLen;
        }
    };
    