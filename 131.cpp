// palindrome partitioning 

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string> path;

        pal(0,s,ans,path);
        return ans;
    }

    void pal(int ind,string s,vector<vector<string>>& ans, vector<string>& path){
        if(ind>= s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = ind ;i<s.size();++i){
            if(ispal(s,ind,i)){

            path.push_back(s.substr(ind,i-ind+1));

            pal(i+1,s,ans,path);

            // backtrack
            path.pop_back();
            }
        }
    }

    bool ispal(string s,int start , int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};