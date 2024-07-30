// brute approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int profit = 0;
            for(int j=i+1;j<n;j++){
                profit = prices[j]-prices[i];
                maxi=max(profit , maxi);
            }
        }
        if(maxi < 0)return 0;
        else return maxi;
    }
};

// better approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi = 0;
        int element = prices[0];
        for(int i=1;i<n;i++){
            int profit = prices[i]-element;
            if(profit<0)element=prices[i];
            else maxi = max(profit , maxi);
        }
        return maxi;
    }
};