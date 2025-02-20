// largest rectangle in histogram 

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<int>st;
            int maxar = 0;
            for(int i =0;i<=n;i++){
                while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty()? i: i-st.top()-1;
                    maxar = max(maxar , height*width);
                }
                st.push(i);
            }
            return maxar;
        }
    };