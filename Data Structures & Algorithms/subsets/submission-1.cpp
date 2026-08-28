class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; // Stores all subsets we generate
        vector<int> subset; // Stores the current subset we are building

        dfs(nums, 0, subset, res); // Start DFS from index 0

        return res;
    }

private:
    // DFS function:
    // nums    -> input array
    // i       -> current index we are deciding on
    // subset  -> current subset being built
    // res     -> stores all generated subsets
    void dfs(const vector<int>& nums, int i,
             vector<int>& subset, vector<vector<int>>& res) {

        // We have made a decision for every element, so the current subset is complete.
        if (i >= nums.size()) {
            res.push_back(subset);

            return;
        }

        // Choice 1: INCLUDE nums[i] in the subset
        subset.push_back(nums[i]);

        // Move to the next element
        dfs(nums, i + 1, subset, res);

        // Backtrack: Remove nums[i] so we can try the other choice
        subset.pop_back();

        // Choice 2: EXCLUDE nums[i] from the subset
        dfs(nums, i + 1, subset, res);
    }
};