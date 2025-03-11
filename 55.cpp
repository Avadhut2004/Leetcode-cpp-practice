// jump game 
// tc = o(n)
// sc = o(1)

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxreach = 0;
            int len = nums.size();
    
            for(int i=0;i<len;i++){
                if(i>maxreach) return false;
    
                else{
                    maxreach = max(maxreach , i+nums[i]);
                }
    
                if(maxreach >= len-1) return true;
            }
            return false;
        }
    };class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;
        int len = nums.size();

        for(int i=0;i<len;i++){
            if(i>maxreach) return false;

            else{
                maxreach = max(maxreach , i+nums[i]);
            }

            if(maxreach >= len-1) return true;
        }
        return false;
    }
};