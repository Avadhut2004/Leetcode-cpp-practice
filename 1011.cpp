class Solution {
public:
    public:
    int daysRequired(vector<int>& weights, int cap) {
        int days = 1, load = 0;
        for (int weight : weights) {
            if (load + weight > cap) {
                days++;
                load = weight; // Start a new day with the current package
            } else {
                load += weight; // Add the weight to the current day's load
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // Minimum capacity: largest single weight
        int high = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity: sum of all weights

        while (low < high) { // Binary search for the minimum valid capacity
            int mid = low + (high - low) / 2; // Avoid overflow
            int daysReq = daysRequired(weights, mid);

            if (daysReq <= days) {
                high = mid; // Try to lower the capacity
            } else {
                low = mid + 1; // Increase the capacity
            }
        }

        return low; // At this point, low == high, which is the minimum capacity
    }
};