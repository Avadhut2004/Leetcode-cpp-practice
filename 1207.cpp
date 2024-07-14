class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mcount;
        set<int> scount;

        for(int i:arr){
            if(mcount.count(i)==0)mcount[i];
            else mcount[i]++;
        }

        for(map<int,int>::iterator i=mcount.begin();i!=mcount.end();i++){
            if(scount.count(i->second)==0)scount.insert(i->second);
            else return false;
        }
        return true;
    }
};