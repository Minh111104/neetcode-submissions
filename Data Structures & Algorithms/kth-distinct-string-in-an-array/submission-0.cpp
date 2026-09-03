class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, bool> mp;
        int count = 0;

        // Count occurrences of each string
        for (const string& item : arr) {
            if (mp.find(item) != mp.end()) {
                mp[item] = false;  // Mark as not distinct
            } else {
                mp[item] = true;   // Mark as distinct
            }
        }

        // Find the k-th distinct string
        for (const string& item : arr) {
            if (mp[item]) {  // Check if it's distinct
                count++;
                if (count == k) {
                    return item;
                }
            }
        }

        return "";  // Return empty string if not found
    }
};