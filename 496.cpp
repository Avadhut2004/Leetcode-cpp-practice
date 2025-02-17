// next greater element 

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> temp; // Stores the next greater elements
            stack<int> st;
            vector<int> ans;
    
            // Process nums2 to find next greater elements
            for (int i = nums2.size() - 1; i >= 0; i--) {
                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();  // Remove smaller elements
                }
                temp[nums2[i]] = st.empty() ? -1 : st.top();
                st.push(nums2[i]);
            }
    
            // Find results for nums1 using the map
            for (int num : nums1) {
                ans.push_back(temp[num]);  // Fetch from unordered_map
            }
            return ans;
        }
    };
    