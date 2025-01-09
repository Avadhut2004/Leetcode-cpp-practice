// Following is the brute force solution

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!=nums[i+1])return nums[i];
            }
            if(i==n-1){
                if(nums[i]!=nums[i-1])return nums[i];
            }
            else{
                if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])return nums[i];
            }
            
        }
        return -1;
    }
};
// for optimal solution 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low = 1, high=n-2;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if((mid%2 == 0 && nums[mid+1]==nums[mid] )|| (mid%2 == 1 && nums[mid-1]==nums[mid])){
                // eliminate left half 
                low = mid+1;
            }
            else high=mid-1;//eliminate right half
        }
        return -1;
    }
};