//  alternating groups 3 
// tc = o(n)
// sc = o(1)

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            if (k > n) return 0; // No valid groups possible
    
            int count = 0;
            int alternatingLength = 1;
    
            // Iterate over an extended version of colors (simulate circular array)
            for (int i = 1; i < n + k - 1; ++i) {
                if (colors[i % n] != colors[(i - 1) % n]) {
                    alternatingLength++;
                } else {
                    alternatingLength = 1;
                }
    
                if (alternatingLength >= k) {
                    count++;
                }
            }
    
            return count;
        }
    };
