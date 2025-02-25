// maximum points you can obtain from cards 
// tc = o(n) sc = o(1)

class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
            int windowsize = cardPoints.size()-k;
            if(cardPoints.size()==k)return total;
            int currsize = accumulate(cardPoints.begin(),cardPoints.begin()+windowsize,0);
            int minsum = currsize;
    
            // sliding the window to find minimum sum 
            for(int i = windowsize ; i<cardPoints.size();i++){
                currsize+=cardPoints[i]-cardPoints[i-windowsize];
                minsum =  min(minsum , currsize);
            }
    
            return total - minsum;
        }
    };