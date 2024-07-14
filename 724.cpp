class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l=0;
        int r= accumulate(nums.begin()+1,nums.end(),0);
        if(r==0)return 0;
        for (int i=1;i<nums.size();i++){
            r-=nums[i];
            l+=nums[i-1];
            if(l==r)return i;
        }
        return -1;
    }
};