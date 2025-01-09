class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int low= 0 , high = n-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[low]<=nums[mid])//  left half sorted 
            {
                ans = min(nums[low],ans);
                low = mid+1;
            }
            else {// right half sorted 
                ans = min(nums[mid],ans);
                high = mid-1;
            }
        }
        return ans ;
    }
};