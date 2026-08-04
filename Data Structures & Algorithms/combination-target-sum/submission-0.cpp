class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curr, const vector<int>& candidates, int index, int target, int sum) {
      if (sum >= target) {
        if (sum == target) {
          res.push_back(curr);
        }
        return;
      }
      for (int option = index; option < candidates.size(); ++option) {
        curr.push_back(candidates[option]);
        backtrack(res, curr, candidates, option, target, sum + candidates[option]);
        curr.pop_back();
      }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> curr;
      backtrack(res, curr, candidates, 0, target, 0);
      
      return res;
    }
};