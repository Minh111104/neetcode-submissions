/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    // Encodes a tree into a single string using preorder traversal.
    string serialize(TreeNode* root) {
        string data;
        serializeDFS(root, data);
        return data;
    }

    // Decodes the encoded string back into the original tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
    }

private:
    void serializeDFS(TreeNode* node, string& data) {
        // Use "#" to represent a null child
        if (!node) {
            data += "#,";
            return;
        }
        // Preorder: current node, left subtree, right subtree
        data += to_string(node->val) + ",";

        serializeDFS(node->left, data);
        serializeDFS(node->right, data);
    }

    TreeNode* deserializeDFS(stringstream& ss) {
        string value;

        // Read the next token separated by a comma
        getline(ss, value, ',');

        // "#" represents a null node
        if (value == "#") {
            return nullptr;
        }
        // Create the current node
        TreeNode* node = new TreeNode(stoi(value));

        // Rebuild the left and right subtrees
        node->left = deserializeDFS(ss);
        node->right = deserializeDFS(ss);

        return node;
    }
};