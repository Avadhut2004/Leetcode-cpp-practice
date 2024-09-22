class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n = nums.size();
       int high =n-1,low = 0;
       while(high>=low){
        int mid = (high+low)/2;
        if(nums[mid]==target)return true;
        else if(nums[low]==nums[high] && nums[high]==nums[mid]){
            low++;
            high--;
        }
        else if(nums[low]<=nums[mid]) // left sorted 
            {
                if(target<=nums[mid] && target>=nums[low])high = mid-1;
                else low = mid+1;
            }
        else {
            if(target>=nums[mid] && target <= nums[high])low = mid+1;
            else high = mid-1;
        }
       }
       return false; 
    }
};