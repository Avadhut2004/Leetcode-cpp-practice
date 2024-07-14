// Approach 1 : Brute

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.size())return false;

        map<char ,int> mcount1;
        map<char,int> mcount2;
        vector<int> vcount1,vcount2;

        for(char ch:word1){
            if(mcount1.find(ch)==mcount1.end())mcount1[ch];
            else mcount1[ch]++;
        }
        for(char ch:word2){
            if(mcount2.find(ch)==mcount2.end())mcount2[ch];
            else mcount2[ch]++;
        }
        for(map<char,int> :: iterator it=mcount1.begin();it!=mcount1.end();it++){
            if(mcount2.find(it->first)==mcount2.end())return false;
            vcount1.push_back(it->second);
        }
        for(map<char,int> :: iterator it=mcount2.begin();it!=mcount2.end();it++){
            if(mcount1.find(it->first)==mcount1.end())return false;
            vcount2.push_back(it->second);
        }
        sort(vcount1.begin(),vcount1.end());
        sort(vcount2.begin(),vcount2.end());
        return (vcount1==vcount2);
    }
};

// Better approach 

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26),b=a;

        for(char i:word1){
            a[i-'a']++;
        }
        for(char i:word2)b[i-'a']++;

        for(int i=0;i<26;i++){
            if(!a[i] && b[i] || a[i] && !b[i])return false;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        return a==b;
    }
};