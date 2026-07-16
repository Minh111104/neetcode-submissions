class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26,0); // frequency of each char
        int l = 0; 
        int maxCount = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxCount = max(maxCount, count[s[r]-'A']);

            // If more than k replacements needed, shrink window
            while ((r-l+1) - maxCount > k) {
                count[s[l] - 'A']--;    // remove s[l] from the window's counts
                l++;    // move the left edge rightward to reduce window size
            }
            res = max(res, (r-l+1));
        }
        return res;
    }
};