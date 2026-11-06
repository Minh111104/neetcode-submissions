class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int ROWS = board.size(), COLS = board[0].size();
        vector<string> res;

        for (string& word : words) {
            bool flag = false;
            for (int r = 0; r < ROWS && !flag; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (board[r][c] != word[0]) continue;
                    if (backtrack(board, r, c, word, 0)) {
                        res.push_back(word);
                        flag = true;
                        break;
                    }
                }
            }
        }
        return res;
    }

private:
    bool backtrack(vector<vector<char>>& board, int r, int c, string& word, int i) {
        if (i == word.length()) return true;
        if (r < 0 || c < 0 || r >= board.size() ||
            c >= board[0].size() || board[r][c] != word[i])
            return false;

        board[r][c] = '*';
        bool ret = backtrack(board, r + 1, c, word, i + 1) ||
                   backtrack(board, r - 1, c, word, i + 1) ||
                   backtrack(board, r, c + 1, word, i + 1) ||
                   backtrack(board, r, c - 1, word, i + 1);
        board[r][c] = word[i];
        return ret;
    }
};