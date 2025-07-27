// binary search to find a target index 

// iterative approach 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (high + low)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};

// recursive approach 
// TC,SC = O(logn)
class Solution {
public:

    int bsRecursive(int low , int high , vector<int>&nums,int target){

        if(low>high)return -1;

        int mid = (low+high)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target) return bsRecursive(low,mid-1,nums,target);
        else return bsRecursive(mid+1,high,nums,target);
    }

    int search(vector<int>& nums, int target) {
        int low=0;
        int high = nums.size()-1;
        return bsRecursive(low,high,nums,target);
        
    }
};