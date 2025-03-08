// valid parenthesis 
// using greedy tc = O(n) sc = O(1);

class Solution {
    public:
        bool checkValidString(string s) {
            int min = 0, max = 0;
            for (char c : s) {
                if (c == '(') {
                    min++;
                    max++;
                } 
                else if (c == ')') {
                    min--;
                    max--;
                } 
                else { // '*' case
                    min--; // '*' can be ')'
                    max++; // '*' can be '('
                }
                
                if (min < 0) min = 0; // Reset min to 0
                if (max < 0) return false; // Too many ')'
            }
            return min == 0;
        }
    };
    