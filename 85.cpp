// maximal rectangle

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            if(matrix.empty()) return 0;
            int m = matrix.size(), n = matrix[0].size();
            vector<int> heights(n, 0);
            int maxArea = 0;
    
            for (int i = 0; i < m; i++) {
                // Build histogram for each row
                for (int j = 0; j < n; j++) {
                    heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
                }
                // Apply Largest Rectangle in Histogram (LeetCode 84)
                maxArea = max(maxArea, largestRectangleArea(heights));
            }
            
            return maxArea;
        }
    
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<int> st;
            int maxArea = 0;
    
            for (int i = 0; i <= n; i++) { // Iterate one extra time to process remaining stack elements
                while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i : i - st.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                if (i < n) st.push(i);
            }
    
            return maxArea;
        }
    };
    