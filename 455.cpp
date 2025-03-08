// assign cookies
// tc = O(nlogn+mlogm+m);
// sc = O(1)
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            int n = g.size();
            int m = s.size();
    
            int r =0,l=0;
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            while(l<m){
                if(r<n && g[r]<=s[l]){
                    r+=1;
                }
                l+=1;
            }
            return r;
        }
    };