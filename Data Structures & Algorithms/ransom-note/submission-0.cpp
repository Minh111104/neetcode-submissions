class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp; // store the char and its frequency

        for (auto c : magazine) {
            mp[c]++;    // add char & frequency to map
        }
        
        for (auto c : ransomNote) {
            if (mp[c] <= 0) {   // all occurence has been used
                return false;
            }
            mp[c]--;
        }
        return true;
    }
};