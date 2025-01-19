// remove outermost parenthisis 

class Solution {
public:
    string removeOuterParentheses(string s) {
        int flag = 0;
        string ans;
        for (int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(flag>=1) ans.push_back(s[i]);

            flag++;
            }
            else{
                flag--;
                if(flag>=1) ans.push_back(s[i]);

            }
        }
    return ans;
    }
};