// checking for a substring in the given string

class Solution {
private:
    // Function to check if two frequency arrays are equal
    bool check(int count1[], int count2[]) {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        // If s1 is longer than s2, s1 cannot be a permutation of any substring of s2
        if (l1 > l2) return false;

        // Frequency array for characters in s1
        int count1[26] = {0};
        for (int i = 0; i < l1; i++) {
            count1[s1[i] - 'a']++;
        }

        // Frequency array for the current window in s2
        int count2[26] = {0};
        for (int i = 0; i < l1; i++) {
            count2[s2[i] - 'a']++;
        }

        // Check the first window
        if (check(count1, count2)) return true;

        // Slide the window across s2
        for (int i = l1; i < l2; i++) {
            // Add the new character to the window
            count2[s2[i] - 'a']++;
            // Remove the character that is no longer in the window
            count2[s2[i - l1] - 'a']--;

            // Check if the updated window matches the frequency of s1
            if (check(count1, count2)) return true;
        }

        return false;
    }
};
