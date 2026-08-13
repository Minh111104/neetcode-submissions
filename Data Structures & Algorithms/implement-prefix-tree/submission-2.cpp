class TrieNode {
public:

    // Each node can have up to 26 children,
    // one for each lowercase English letter:
    // child[0] = 'a', child[1] = 'b', ..., child[25] = 'z'
    TrieNode *child[26];

    // True if a complete word ends at this node.
    // False if this node is only part of a word/prefix.
    bool isWord;

    // Constructor for a new TrieNode
    TrieNode() {

        // Initially, this node does not represent the end of a complete word.
        isWord = false;

        // Initially, this node has no children. Set all 26 pointers to nullptr.
        for (auto &a : child)
            a = nullptr;
    }
};


class PrefixTree {
    // Pointer to the root node of the Trie. The root does not represent any character.
    TrieNode* root;

public:
    // Constructor for the PrefixTree
    PrefixTree() {
        root = new TrieNode(); // Create an empty root node.
    }

    // Insert a word into the Trie.
    void insert(string s) {

        // Start at the root.
        TrieNode *p = root;

        // Go through each character in the string.
        for (auto &a : s) {

            // Convert the character into an index from 0 to 25.
            //
            // 'a' - 'a' = 0
            // 'b' - 'a' = 1
            // 'c' - 'a' = 2
            // ...
            // 'z' - 'a' = 25
            int i = a - 'a';

            // If the current node does not have
            // a child for this character,
            // create a new TrieNode.
            if (!p->child[i])
                p->child[i] = new TrieNode();

            // Move p to the child node.
            // We are now processing the next character.
            p = p->child[i];
        }

        // We have reached the end of the word.
        // Mark this node as the end of a complete word.
        p->isWord = true;
    }


    // Search for a word or prefix.
    //
    // prefix = false → search for an exact word
    // prefix = true  → search only for a prefix
    bool search(string key, bool prefix=false) {

        // Start at the root.
        TrieNode *p = root;

        // Go through every character in key.
        for (auto &a : key) {

            // Convert the character to an index 0-25.
            int i = a - 'a';

            // If this character does not have
            // a corresponding child, the word/prefix
            // does not exist in the Trie.
            if (!p->child[i])
                return false;

            // Move to the node representing this character.
            p = p->child[i];
        }

        // If we are doing a normal word search,
        // we need to check whether a complete word
        // actually ends at this node.
        if (prefix == false)
            return p->isWord;

        // If we are checking a prefix, reaching this node
        // is enough. We don't care whether a complete word
        // ends here.
        return true;
    }


    // Check whether any previously inserted word
    // starts with the given prefix.
    bool startsWith(string prefix) {

        // Call search(), but tell it that we are
        // checking a prefix instead of an exact word.
        return search(prefix, true);
    }
};