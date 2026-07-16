class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;  
        int maxLength = 0;
        unordered_map<char, int> mp;  // Map to store the index of the characters

        for (int r = 0; r < s.size(); r++) { 
            // If the character at s[r] has been seen and is inside the current window
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;  // Move the left pointer to skip over the repeated character
            }
            mp[s[r]] = r;  // Update the last seen index of the character
            maxLength = max(maxLength, r - l + 1);  // Update max length
        }
        return maxLength;
    }
};