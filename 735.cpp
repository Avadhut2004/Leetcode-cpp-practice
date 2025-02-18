// asteroid collision 

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> ans;
            stack<int> st;
    
            for (int i = 0; i < asteroids.size(); ++i) {
                int curr = asteroids[i];
    
                // Process collisions if current asteroid is moving left (negative) and the stack has a moving right (positive)
                while (!st.empty() && st.top() > 0 && curr < 0) {
                    // If the current asteroid is smaller, it is destroyed
                    if (abs(curr) < abs(st.top())) {
                        curr = 0;
                    }
                    // If the current asteroid is larger, pop the stack
                    else if (abs(curr) > abs(st.top())) {
                        st.pop();
                    }
                    // If the two asteroids are equal, both are destroyed
                    else {
                        st.pop();
                        curr = 0;
                    }
                }
    
                // If the asteroid is still alive (not destroyed), push it to the stack
                if (curr != 0) {
                    st.push(curr);
                }
            }
    
            // Fill the answer vector from the stack
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
    
            // Since we filled the answer in reverse order, reverse it before returning
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    