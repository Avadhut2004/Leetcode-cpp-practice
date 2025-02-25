// string to integer (atoi)

// tc = o(n) sc = O(n) (rescursive stack)


class Solution {
    public:
        int myAtoi(string s) {
            int i = 0;
            int n = s.length();
            long res = 0;
            int sign=1;
    
            // skipping leading spaces 
            while(i<n && s[i]==' ')i++;
    
            //sign
            if(s[i]=='+' || s[i]=='-'){
                sign = s[i]=='-' ? -1:1;
                i++;
            }
            return convert(s,i,res,sign);
        }
    
        int convert(string s , int i , long res , int sign){
            if(i>=s.size() || !isdigit(s[i])) return res*sign;
    
            res = res*10 + (s[i]-'0');
    
            if(res*sign>=INT_MAX) return INT_MAX;
            if(res*sign<=INT_MIN) return INT_MIN;
    
            return convert(s,i+1,res,sign);
        }
    };