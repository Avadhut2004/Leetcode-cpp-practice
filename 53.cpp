// brute approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi = INT_MIN;
        for ( int i=0;i<n;i++){
            int sum = 0;
            for ( int j=i;j<n;j++){
                sum = sum+nums[j];
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};

// Kadane's algo

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi = max(maxi,sum);
            if(sum<0)sum=0;
        }
        return maxi;
    }
};