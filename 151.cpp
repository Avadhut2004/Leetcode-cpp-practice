// reverse words in string 
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        int n = s.size();
        int i = 0, j = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') i++; // Skip leading spaces
            while (i < n && s[i] != ' ') s[j++] = s[i++]; // Copy word
            while (i < n && s[i] == ' ') i++; // Skip trailing spaces
            if (i < n) s[j++] = ' '; // Add single space between words
        }
        s.resize(j); // Resize to remove extra characters
        
        // Step 2: Reverse the entire string
        reverse(s.begin(), s.end());
        
        // Step 3: Reverse each word
        int start = 0;
        for (int k = 0; k <= s.size(); k++) {
            if (k == s.size() || s[k] == ' ') {
                reverse(s.begin() + start, s.begin() + k);
                start = k + 1;
            }
        }
        
        return s;
    }
};
