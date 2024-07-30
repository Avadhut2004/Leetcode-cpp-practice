// brute approach

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos;
        vector<int>neg;
        for(auto it : nums){
            if (it>0)pos.push_back(it);
            else neg.push_back(it);
        }

        for ( int i=0;i<n/2;i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        return nums;
    }
};

// optimal approach;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     int size = nums.size();
     vector<int>ans(size);
        int p=0;int n=1;
        for(int i =0;i<size;i++){
            if(nums[i]>0){
                ans[p] = nums[i];
                p+=2;
            }
            else{
                ans[n] = nums[i];
                n+=2;
            }
        }
            return ans;
    }
};