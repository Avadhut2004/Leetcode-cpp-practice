// sliding window maximal

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq; // Stores indices of elements in decreasing order
            vector<int> ans;
            
            for(int i = 0; i < nums.size(); i++) {
                // Remove elements from the front if they are out of this window
                if(!dq.empty() && dq.front() == i - k) {
                    dq.pop_front();
                }
    
                // Remove smaller elements as they are useless (maintaining decreasing order)
                while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                    dq.pop_back();
                }
    
                // Insert the current element index
                dq.push_back(i);
    
                // Start pushing max values to ans after the first `k` elements
                if(i >= k - 1) {
                    ans.push_back(nums[dq.front()]);
                }
            }
    
            return ans;
        }
    };
    