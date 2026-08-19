class TrieNode {
public:
    unordered_map<char, TrieNode*> children;  // Maps each character to the next Trie node
    bool isWord;                              // True if a word ends at this node

    TrieNode() {
        isWord = false;
    }

    // Insert a word into the Trie
    void addWord(const string& word) {
        TrieNode* cur = this;  // Start from the current node

        for (char c : word) {
            // Create a node if this character doesn't exist
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }

            cur = cur->children[c];  // Move to the next node
        }

        cur->isWord = true;  // Mark the end of the word
    }
};


class Solution {
    unordered_set<string> res;       // Stores found words (automatically removes duplicates)
    vector<vector<bool>> visit;      // Tracks cells currently used in DFS

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        // Build a Trie containing all target words
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }

        int ROWS = board.size(), COLS = board[0].size();

        // Initially, no board cells have been visited
        visit.assign(ROWS, vector<bool>(COLS, false));

        // Start DFS from every cell on the board
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                dfs(board, r, c, root, "");
            }
        }

        // Convert the set of results into a vector
        return vector<string>(res.begin(), res.end());
    }

private:
    // DFS to find words starting from (r, c)
    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, string word) {

        int ROWS = board.size(), COLS = board[0].size();

        // Stop if:
        // - outside the board
        // - cell was already visited
        // - current character doesn't exist in the Trie
        if (r < 0 || c < 0 || r >= ROWS ||
            c >= COLS || visit[r][c] ||
            !node->children.count(board[r][c])) {
            return;
        }

        visit[r][c] = true;                       // Mark current cell as visited
        node = node->children[board[r][c]];      // Move to the matching Trie node
        word += board[r][c];                     // Add current character to the word

        // If this Trie node represents a complete word, save it
        if (node->isWord) {
            res.insert(word);
        }

        // Explore the four neighboring cells
        dfs(board, r + 1, c, node, word);  // Down
        dfs(board, r - 1, c, node, word);  // Up
        dfs(board, r, c + 1, node, word);  // Right
        dfs(board, r, c - 1, node, word);  // Left

        visit[r][c] = false;  // Backtrack: allow this cell to be used again
    }
};