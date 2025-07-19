// house robber 
// using dp 
// tabulation => tc = O(n) sc = O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
     int n = nums.size();
     if(n==0)return 0;
     if(n==1)return nums[0];

     vector<int>dp(n,0);
    dp[0]=0;
    dp[1]=max(nums[0],nums[1]);
     for(int i=2;i<n;i++){
        int pick = nums[i]+dp[i-2];

        int ntpick = dp[i-1];

        dp[i]=max(pick,ntpick);
     }   

     return dp[n-1];
    }
};

//  space optimization (tc = o(n), sc = O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1;i<n;i++){
            int pick = nums[i] ;
            if(i>1) pick+= prev2;

            int ntpick = prev;
            int curi = max(pick,ntpick);

            prev2 = prev;
            prev = curi;
            
        }
return prev;
    }
};