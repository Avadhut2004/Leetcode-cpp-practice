class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if (nums.size()<1)return 0;
        int longest = 1;
        int lastele= INT_MIN;
        int count = 1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]-1==lastele){
                lastele = nums[i];
                count++;
            }
            else if (nums[i]!=lastele){
                count =1;
                lastele = nums[i];
            }
            longest = max(longest ,count);
            
        }return longest;
    }
};