class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int slow, fast;
       
        for(slow = 0, fast = 0; fast < A.size(); ++fast){
            if(A[fast] == 0) --K;
           
            if(K < 0 && A[slow++] == 0) ++K;
        }
        
        return fast - slow;
    }
};