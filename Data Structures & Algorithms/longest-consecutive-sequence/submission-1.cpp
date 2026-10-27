class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int curLen = 1;

                while (numSet.find(num + curLen) != numSet.end()) {
                    curLen++;
                }
                longest = max(longest, curLen);
            }
        }
        return longest;
    }
};
