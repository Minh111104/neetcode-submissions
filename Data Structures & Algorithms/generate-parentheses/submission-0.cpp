class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(res, cur, n, n);  // start with n left and n right

        return res;        
    }

    void backtrack(vector<string>& res, string& cur, int l, int r) {
        // If no more parentheses to add, we have a valid string
        if (l == 0 && r == 0) {
            res.push_back(cur);
            return;
        }

        // Add "(" if any left remain
        if (l > 0) {
            cur.push_back('(');
            backtrack(res, cur, l - 1, r);
            cur.pop_back();
        }

        // Add ")" if we have more ")" left than "(" (to maintain validity)
        if (r > l) {
            cur.push_back(')');
            backtrack(res, cur, l, r - 1);
            cur.pop_back();
        }
    }
};