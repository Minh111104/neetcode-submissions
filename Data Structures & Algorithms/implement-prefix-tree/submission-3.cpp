class TrieNode {
public:

    // Each node has 26 possible children,
    // one for each lowercase English letter.
    //
    // children[0]  -> 'a'
    // children[1]  -> 'b'
    // ...
    // children[25] -> 'z'
    TrieNode* children[26];

    // True if a complete word ends at this node.
    // False if this node is only part of a word.
    bool endOfWord;

    // Constructor: initialize a new TrieNode
    TrieNode() {

        // Initially, this node has no children.
        // Set all 26 child pointers to nullptr.
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }

        // Initially, no word ends at this node.
        endOfWord = false;
    }
};


class PrefixTree {

    // Pointer to the root of the Trie.
    //
    // The root does NOT represent a character.
    // It is simply where we start traversing the Trie.
    TrieNode* root;

public:

    // Constructor for the PrefixTree
    PrefixTree() {

        // Create an empty root node.
        root = new TrieNode();
    }


    // Insert a word into the Trie.
    void insert(string word) {

        // Start at the root.
        TrieNode* cur = root;

        // Process each character in the word.
        for (char c : word) {

            // Convert the character into an index from 0 to 25.
            //
            // 'a' - 'a' = 0
            // 'b' - 'a' = 1
            // 'c' - 'a' = 2
            // ...
            // 'z' - 'a' = 25
            int i = c - 'a';

            // If there is no child for this character,
            // create a new TrieNode.
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }

            // Move to the child node.
            //
            // For example, if c = 'a',
            // move to children[0].
            cur = cur->children[i];
        }

        // We have reached the end of the word.
        // Mark this node as the end of a complete word.
        cur->endOfWord = true;
    }


    // Search for an exact word in the Trie.
    bool search(string word) {

        // Start at the root.
        TrieNode* cur = root;

        // Go through each character in the word.
        for (char c : word) {

            // Convert the character to an index 0-25.
            int i = c - 'a';

            // If this character does not have
            // a corresponding child, the word does not exist.
            if (cur->children[i] == nullptr) {
                return false;
            }

            // Move to the node representing this character.
            cur = cur->children[i];
        }

        // We successfully followed every character.
        //
        // However, we still need to check whether
        // this node represents the END of a complete word.
        //
        // This is important because the word could simply
        // be a prefix of another word.
        return cur->endOfWord;
    }


    // Check whether there is a previously inserted word
    // that starts with the given prefix.
    bool startsWith(string prefix) {

        // Start at the root.
        TrieNode* cur = root;

        // Process each character in the prefix.
        for (char c : prefix) {

            // Convert the character to an index 0-25.
            int i = c - 'a';

            // If the path does not exist,
            // no word can have this prefix.
            if (cur->children[i] == nullptr) {
                return false;
            }

            // Move to the next node.
            cur = cur->children[i];
        }

        // We successfully followed the entire prefix.
        //
        // We don't care whether this node is the end
        // of a complete word. There could be more characters
        // after this prefix.
        return true;
    }
};