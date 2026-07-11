class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;

        for (int num  : nums) {
            if (numSet.find(num) != numSet.end()) {
                return true;
            }
            numSet.insert(num);
        }
        return false;
    }
};