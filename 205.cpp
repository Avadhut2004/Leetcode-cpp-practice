// isomorphic strings 
// optimal solution using unordered map 
// TC = O(n) SC = O(1)


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_to_t , t_to_s;

        for(int i=0;i<s.length();i++){
            char s_char = s[i] , t_char = t[i];

            // checking for mismatch in s to t 
            if(s_to_t.count(s_char) && s_to_t[s_char]!=t_char) return false;

            // checking for mismatch in t to s 
            if(t_to_s.count(t_char) && t_to_s[t_char]!=s_char) return false;

            // if not both then put a mapping 
            s_to_t[s_char]=t_char;
            t_to_s[t_char]=s_char;
        }
        return true;
    }
};