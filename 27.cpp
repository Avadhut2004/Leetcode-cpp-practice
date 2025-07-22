// remove elements 

// two pointers 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int k=0;
        for(auto x:nums){
            if(x!=val) nums[k++]=x;
        }
        return k;

    }
};

//  approach 2 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==val){
                nums[i]=nums[--n];
            }
            else i++;
        }
        return i;
    }
};