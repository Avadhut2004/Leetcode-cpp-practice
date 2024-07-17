class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int dup =x;

        int reverse=0;
        while(x){
            int ld = x%10;
            if(reverse>INT_MAX/10)return false;
            reverse = (reverse*10)+ld;
            x/=10;
        }

        return reverse==dup;
    }
};