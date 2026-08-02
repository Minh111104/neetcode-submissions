class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int index) {
        // Add the current subset to the result
        res.push_back(subset);

        // Explore all possible combinations of elements to form subsets
        // index dùng để chọn số trước đó
        for (int option = index; option < nums.size(); ++option) {
            // Skip duplicates
            if (option > index && nums[option] == nums[option - 1])
                continue;

            // Include the current element in the subset
            subset.push_back(nums[option]);

            // Recur with the updated subset and next index
            backtrack(nums, res, subset, option + 1);

            // Backtrack: Remove the last element from the subset
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // Sort the input to handle duplicates
        // sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, res, subset, 0);
        return res;
    }        
};