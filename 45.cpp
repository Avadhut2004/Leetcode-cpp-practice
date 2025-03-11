//  jump game 2 
//  tc = o(n)
// sc= o(1)

class Solution {
    public:
        int jump(vector<int>& nums) {
            int l = 0 , r = 0, farthest = 0,jmps=0;
            int len = nums.size();
            while(r<len-1){
                for(int i=l;i<=r;i++){
                    farthest = max(i+nums[i],farthest);
                }
                l = r+1;
                r = farthest;
                jmps++;
            }
            return jmps;
        }
    };