class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;
        
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            char sChar = s[i];
            char tChar = t[i];
            
            // Check if sChar already maps to a different character in t
            if (sToT.find(sChar) != sToT.end() && sToT[sChar] != tChar) {
                return false;
            }
            // Check if tChar already maps to a different character in s
            if (tToS.find(tChar) != tToS.end() && tToS[tChar] != sChar) {
                return false;
            }
            // Update the mappings
            sToT[sChar] = tChar;
            tToS[tChar] = sChar;
        }
        return true;    
    }
};