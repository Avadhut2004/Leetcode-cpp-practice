// largest odd  number in a string 

class Solution {
public:
    string largestOddNumber(string num) {
        int last = num.length()-1;
        while(last >= 0){
            if((num[last]-'0')%2 == 1) break;

            last --;
        }

        if(last <0) return "";

        return num.substr(0,last+1);
    }
};