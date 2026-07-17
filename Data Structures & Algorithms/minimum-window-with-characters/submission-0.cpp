class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> countT; // frequency of characters in t
        unordered_map<char,int> window; // frequency inside the current window

        if (t.empty()) {
            return "";
        }

        for (char c : t) {
            countT[c]++;
        }
        int have = 0; // # of distinct characters currently meet the required count
        int need = countT.size(); // # of distinct characters we need to match
        pair<int,int> res = {-1, -1}; // store (left,right) of the smallest window found
        int resLen = INT_MAX; // initially equal infinity 
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            // check if the character is needed && if we reach exactly the required frequency
            if (countT.find(s[r]) != countT.end() && window[s[r]] == countT[s[r]]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1; // update best result of current window
                    res = {l, r};
                }
                window[s[l]]--; // shrink from the left
                
                // check if we lose a required character
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
