// maximum nesting depth of the parantheses 

class Solution {
public:
    int maxDepth(string s) {
        int cnt =0;
        int maxCount= INT_MIN;

        for(char c:s){
            if(c=='(')cnt++;
            if(c==')')cnt--;
            maxCount = max(maxCount,cnt);
        }

        return maxCount;
    }
};
