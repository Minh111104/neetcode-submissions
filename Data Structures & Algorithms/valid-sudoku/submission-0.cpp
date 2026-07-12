class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> boxes[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }
                char val = board[r][c];
                int boxIdx = (r / 3) * 3 + (c / 3);

                if (rows[r].count(val) || cols[c].count(val) || boxes[boxIdx].count(val)) {
                    return false;
                }
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[boxIdx].insert(val);
            }
        }
        return true;        
    }
};
