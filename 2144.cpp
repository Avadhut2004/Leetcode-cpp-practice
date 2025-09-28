class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());

        int end = n - 1;
        int total = 0;

        while (end >= 0) {
            while (end >= 0) {
                for (int i = 0; i < 2 && end >= 0;
                     i++) { // pick 2 most expensive
                    total += cost[end--];
                }
                end--; // skip the 3rd (cheapest in this triple)
            }
        }
        return total;
    }
};
