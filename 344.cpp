// reverse a string 
// TC = O(n) SC = O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0 ; 
        int end = s.size()-1;

        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
};