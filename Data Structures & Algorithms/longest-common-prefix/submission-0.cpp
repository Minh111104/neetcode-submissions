class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        for (int i = 0; i < strs[0].size(); i++) {  // loop through each char in "flower"
            for (int j = 1; j < strs.size(); j++) { // loop through each char start from "flow"    
                if (strs[j][i] != strs[0][i]) {
                    return res;
                }
            }
            res += strs[0][i];  // if the prefix in first and second word is the same, add to res
        }
        return res;
    }
};