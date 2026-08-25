class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curr, const vector<int>& candidates, int index, int target, int sum) {
        // If the current sum is greater than or equal to the target,
        // check if it equals the target. If so, add the current combination
        // to the result.
        if (sum >= target) {
            if (sum == target) {
                res.push_back(curr);
            }
            return;
        }
        // Start iterating from the current index to avoid duplicates.
        for (int option = index; option < candidates.size(); ++option) {
            // Skip duplicates
            if (option > index && candidates[option] == candidates[option - 1])
                continue;
            
            // Add the current candidate to the combination.
            curr.push_back(candidates[option]);
            
            // Recursively call backtrack with updated parameters.
            // Here, the index is passed as 'option' to avoid reusing the same number.
            backtrack(res, curr, candidates, option + 1, target, sum + candidates[option]);
            
            // Remove the last element to backtrack and try other combinations.
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        // Sort the candidates to ensure that duplicate numbers are adjacent to each other
        sort(candidates.begin(), candidates.end()); 
        
        // Start the backtracking process with initial parameters.
        backtrack(res, curr, candidates, 0, target, 0);
        return res;        
    }
};