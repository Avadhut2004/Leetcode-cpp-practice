// letter combinations of a phone number 

class Solution {
    public:
    
        void letter(string digits , int ind , vector<string>&ans , string&op,vector<string>map){
            if(ind>=digits.length()){
                ans.push_back(op);
                return;
            }
    
            int num = digits[ind]-'0';
            string val = map[num];
    
            for(int i = 0;i<val.length();i++){
                op.push_back(val[i]);
                letter(digits,ind+1,ans,op,map);
    
                op.pop_back();
            }
        }
        vector<string> letterCombinations(string digits) {
            vector<string>ans;
            string op = "";
    
            if(digits.length()==0) return ans;
    
            vector<string> mapp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
            letter(digits,0,ans,op,mapp);
    
            return ans;
        }
    };