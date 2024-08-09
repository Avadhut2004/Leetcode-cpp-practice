// brute solution

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n = nums.size();
        int res=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                res = i;
                break;
            }
        }  
        ans.push_back(res);
        int last =-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                last  = i;
                break;
            }
        }  
        ans.push_back(last);
        return ans;
    }
};

// optimized solution using binary search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
            int n = nums.size();
            int low = 0 , high = n-1;
            int first = -1,last = -1;
            for(int i=0;i<n;i++){
                if(nums[i]==target){first = i;
                break;}
            }
            
            while(low<=high){
                int mid=(high+low)/2;
                if(nums[mid]==target){
                    last = mid;
                    low = mid+1;
                }
                else if(nums[mid]<target){
                    low= mid+1;
                }
                else{
                    high= mid-1;
                }
            }
            ans.push_back(first);
            ans.push_back(last);

        return ans;
    }
};