// next grater element 2

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            vector<int>ans(nums.size());
            stack<int>st;
            int n = nums.size();
            for(int i=(2*n-1);i>=0;i--){
                while(!st.empty() && st.top()<=nums[i%n]){
                    st.pop();
                }
                int anse = st.empty() ? -1: st.top();
                st.push(nums[i%n]);
                if(i<n) ans[i]=anse;
            }
            return ans;
        }
    };