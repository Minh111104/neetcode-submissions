class TrieNode {
public:
    vector<TrieNode*> children;  // 26 pointers, one for each letter a-z
    bool word;                   // true if a word ends at this node

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);  // Initialize all children as null
        word = false;                               // Initially, no word ends here
    }
};

class WordDictionary {
public:
    TrieNode* root;  // Root of the Trie

    WordDictionary() {
        root = new TrieNode();  // Create an empty Trie
    }
    
    void addWord(string word) {
        TrieNode* cur = root;  // Start from the root

        for (char c : word) {
            int i = c - 'a';  // Convert character to index 0-25

            // Create the node if this character path doesn't exist
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }

            cur = cur->children[i];  // Move to the next node
        }

        cur->word = true;  // Mark the end of the word
    }
    
    bool search(string word) {
        return dfs(word, 0, root);  // Search using DFS for '.' cases
    }
    
private:
    // DFS starting from index k and the given Trie node
    bool dfs(const string& word, int k, TrieNode* root) {
        TrieNode* cur = root;

        // Process the word starting from index k
        for (int j = k; j < word.size(); j++) {
            char c = word[j];
            int i = c - 'a';  // Convert character to index

            if (c == '.') {
                // '.' can match any character, so try every child
                for (TrieNode* child : cur->children) {
                    if (child != nullptr && dfs(word, j + 1, child)) {
                        return true;  // Found a matching path
                    }
                }
                return false;  // No child matched
            } else {
                // Normal character: follow its corresponding child
                if (cur->children[i] == nullptr) {
                    return false;  // Character path doesn't exist
                }
                cur = cur->children[i];
            }
        }

        // All characters matched; check if a complete word ends here
        return cur->word;
    }
};