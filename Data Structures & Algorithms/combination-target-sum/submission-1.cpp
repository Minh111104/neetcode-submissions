class Solution {
public:
    vector<vector<int>> res; // Stores all valid combinations

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end()); // stop early when the current sum becomes larger than target

        // Start DFS:
        // i = 0        -> start from the first number
        // {}           -> current combination is empty
        // 0            -> current sum is 0
        dfs(0, {}, 0, nums, target);

        return res;
    }

    void dfs(int i, vector<int> cur, int total, vector<int>& nums, int target) {
        // Base case: a combination whose sum equals target
        if (total == target) {
            res.push_back(cur);

            return;
        }

        for (int j = i; j < nums.size(); j++) { // Try every number starting from index i
            // Because nums is sorted, if nums[j] makes the total too large, all later numbers will also be too large.
            if (total + nums[j] > target) {
                return;
            }

            cur.push_back(nums[j]); // Choose nums[j]

            // Recursively continue.
            // Notice we pass j, NOT j + 1.
            // This allows us to use nums[j] again.
            dfs(j, cur, total + nums[j], nums, target);

            // Backtrack: Remove the number we just chose and try the next number.
            cur.pop_back();
        }
    }
};