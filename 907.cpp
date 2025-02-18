// sum of subarray of minimums 


class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            int mod = 1e9 + 7;
            long long res = 0; // Use long long to avoid overflow issues
    
            stack<int> st;
            vector<int> prev(n, 0), next(n, 0); // prev[i] and next[i] are initialized to 0
    
            // Computing PLE (Previous Less Element)
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                prev[i] = (st.empty() ? i + 1 : i - st.top());
                st.push(i);
            }
    
            // Clearing stack for NLE calculation
            while (!st.empty()) {
                st.pop();
            }
    
            // Computing NLE (Next Less Element)
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                next[i] = (st.empty() ? n - i : st.top() - i);
                st.push(i);
            }
    
            // Computing the final sum
            for (int i = 0; i < n; i++) {
                res = (res + (long long)arr[i] * prev[i] * next[i]) % mod;
            }
    
            return res;
        }
    };
    