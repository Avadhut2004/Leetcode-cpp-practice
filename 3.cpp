// longest substring without duplicates 
// tc = O(n)
// sc = O(1) (at most 26 entries in the map)
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char,int>mp ;
            int left=0 , maxlen = 0;
            for(int right = 0;right<s.length();right++){
               if(mp.find(s[right])!=mp.end()){
                 left = max(left,mp[s[right]]+1);
               }
               mp[s[right]]=right;
               maxlen = max(maxlen,right-left+1);
            }
            return maxlen;
        }
    };