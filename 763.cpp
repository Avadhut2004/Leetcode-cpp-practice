// partition labels
 
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> lastIndex(26, 0);
            vector<int> result;
    
            // Step 1: Record the last occurrence index of each character
            for (int i = 0; i < s.size(); i++) {
                lastIndex[s[i] - 'a'] = i;
            }
    
            // Step 2: Iterate to find partitions
            int maxEnd = 0, start = 0;
            for (int i = 0; i < s.size(); i++) {
                maxEnd = max(maxEnd, lastIndex[s[i] - 'a']);
    
                // If current index reaches maxEnd, finalize partition
                if (i == maxEnd) {
                    result.push_back(i - start + 1);
                    start = i + 1;
                }
            }
    
            return result;
        }
    };
    