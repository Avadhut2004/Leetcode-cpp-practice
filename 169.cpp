// using hashmap

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>map1;
        for(auto it : nums){
            map1[it]++;
        }

        for(auto it :map1){
            if(it.second>(n/2))return it.first;
        }

        return -1;
    }
};
// moore's voting algo 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0 ; int element=0;
        for(auto it:nums){
            if(count==0){
                count ++;
                element=it;
            }
            else if(it == element){
                count++;
            }
            else count--;
        }
        int count2=0;
        for(auto it : nums){
            if(it==element)count2++;
        }
        if(count2>(nums.size()/2))return element;
        else return -1;
    }
};