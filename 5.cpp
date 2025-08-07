// longest palindromic subsequence 

//  approach 1 : dp (tabulation)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1)return s;
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        int maxlen =1;
        int start = 0;

        // for substrings of length 1 : will always be a palindrome 

        for(int i=0 ;i<n;i++) dp[i][i]=true;

        // for length 2 

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){dp[i][i+1]=true;
                             start = i;
                             maxlen = 2;
                             }
        }

        // for length >=3
        // expand out from the current index 
        for(int len = 3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                
                int j = i+len-1;

                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(len>maxlen){
                        start = i;
                        maxlen = len;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};


// approach expanding out 

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1) return s;

        int start =0;
        int end = 0;
        for(int i=0;i<n;i++){
            int len1=expand(s,i,i);
            int len2 = expand(s,i,i+1);

            int len = max(len1,len2);

            if(len>end-start+1){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substr(start,end-start+1);
    
    }

    int expand(string &s,int left , int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};
