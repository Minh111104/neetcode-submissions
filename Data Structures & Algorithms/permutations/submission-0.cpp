class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int index) {
      // base case: All the numbers have been permuted
        if (index == nums.size()) {
            res.push_back(nums);
        }

        for (int option = index; option < nums.size(); ++option) {
            // Skip duplicates
            if (option > index && nums[option] == nums[option - 1]) {
                continue;
            }
            
            // ensures that each element is placed at 'index' position in the permutation at each recursive call
            swap(nums[index], nums[option]);
            
            backtrack(nums, res, index + 1);
            
            // the elements are swapped back to backtrack and try other permutations
            swap(nums[index], nums[option]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);

        return res;
    }
};