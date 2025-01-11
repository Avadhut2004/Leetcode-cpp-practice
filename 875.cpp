class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
 	int left = 1;
	int right = INT_MAX;
	
	while (left < right) {
		int mid = left + (right - left) / 2;
		int total = 0;

		for (int i : piles) {
			total += ceil((i +mid-1)/ mid);
		}
		if (total > H)
			left = mid+1;
		else
			right = mid;
	}

	return left;
    }   
};