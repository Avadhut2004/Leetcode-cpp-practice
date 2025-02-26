// generate valid parenthesis

class Solution {
    public:
        void append(vector<string>&res , string curr,int open , int close, int n){
            if(curr.length() == 2*n){
                res.push_back(curr);
            }
    
            // adding open if available 
            if(open<n)
            append(res,curr+"(",open+1 , close, n);
    
            if(close<open){
                append(res,curr+")",open , close+1,n);
            }
        }
        vector<string> generateParenthesis(int n) {
           vector<string>res;
           append(res,"",0,0,n);
    
           return res;
        }
    };