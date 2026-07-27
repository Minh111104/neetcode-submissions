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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0; // Stores the maximum diameter (number of edges)

        dfs(root, res);

        return res;
    }

private:
    // Returns the height of the current subtree.
    // 'res' is updated with the largest diameter found so far.
    int dfs(TreeNode* root, int& res) {
        // Base case: empty subtree has height 0
        if (!root) {
            return 0;
        }

        // Recursively compute the height of the left subtree
        int left = dfs(root->left, res);

        // Recursively compute the height of the right subtree
        int right = dfs(root->right, res);

        // The longest path passing through this node is:
        // left subtree height + right subtree height
        // Update the global maximum diameter if needed.
        res = max(res, left + right);

        // Return the height of the current subtree.
        // Height = 1 (current node) + taller subtree.
        return 1 + max(left, right);
    }
};
