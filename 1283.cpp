class Solution {
public:
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1,high= *max_element(nums.begin(),nums.end());

        while(low<high){
            int mid = low +(high-low)/2;
            int total = 0;
            for(int i:nums){
                total+= (i+mid-1)/mid;
            }
            if(total>threshold) low = mid+1;
            else high=mid;
        }
        return high;
        
    }
};