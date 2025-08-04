// minimum no of days to make m bouquets 

class Solution {
public:

    bool possible(vector<int>& arr, int day, int m, int k) {
    int count = 0;
    int bouquetsPossible = 0;

    for (auto it : arr) {
        if (it <= day) {
            count++;
            if (count == k) {
                bouquetsPossible++;
                count = 0; // reset for next bouquet
            }
        } else {
            count = 0; // chain broken
        }
    }

    return bouquetsPossible >= m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) return -1;
      int low = *min_element(bloomDay.begin(), bloomDay.end());
int high = *max_element(bloomDay.begin(), bloomDay.end());


        while(low<=high){
            int mid = (low+high)/2;

            if(possible(bloomDay,mid,m,k)==true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};