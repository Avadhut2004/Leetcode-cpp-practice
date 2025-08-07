// sort characters by frequency

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;

        for (char c : s) mp[c]++;

        // Make a max heap with frequency as the first element
        priority_queue<pair<int, char>> maxHeap;

        for (auto& [ch, count] : mp) {
            maxHeap.push({count, ch});
        }

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            ans += string(count, ch);
        }

        return ans;
    }
};
