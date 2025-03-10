// n meetings in a room 
// tc = O(2n+nlogn)
// sc = O(n)


class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      int maxMeetings(vector<int>& start, vector<int>& end) {
          vector<pair<int,int>>p;
          int n = start.size();
          for(int i=0;i<n;i++){
              p.push_back({start[i],end[i]});   // O(n)
          }
          
          sort(p.begin(),p.end(),[](pair<int,int>&a ,pair<int,int>&b){
              return a.second<b.second;                                          // O(n logn )
          });
          
          int cnt = 1;
          int endtime = p[0].second;
          for(int i=1;i<n;i++){
              if(p[i].first>endtime){
                  cnt++;
                  endtime = p[i].second;                   // O(n
              }
          }
          return cnt;
          
      }
  };