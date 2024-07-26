// brute approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        for(int j=0;j<n;j++){
            if(nums[i]!=nums[j])nums[++i]=nums[j];
        }
        return i+1;
    }
};

// better approach using set

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>sorted;
        for(int i=0;i<nums.size();i++){
            sorted.insert(nums[i]);
        }

        int i=0;
        for(auto it : sorted){
            nums[i++]=it;
        }
        return i;
    }
};

