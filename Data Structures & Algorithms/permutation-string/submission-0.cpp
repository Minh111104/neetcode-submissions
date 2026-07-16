class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        if (s1.size() > s2.size()) {
            return false;
        }

        for (int i = 0; i < s1.size(); i++) { // Count frequencies of first window
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++; // count the first s1.size() characters in s2
        }

        if (s1Count == s2Count) { // If first window matches
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) { // Sliding window
            s2Count[s2[i] - 'a']++; // Add new character           
            s2Count[s2[i - s1.size()] - 'a']--; // Remove old character

            // Check again
            if (s1Count == s2Count) {
                return true;
            }
        }
        return false;
    }
};