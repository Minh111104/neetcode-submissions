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
    bool isBalanced(TreeNode* root) {
        // dfs() returns: {isBalanced, height}
        return dfs(root)[0] == 1;
    }

private:
    vector<int> dfs(TreeNode* root) {
        // Empty tree is balanced with height 0
        if (!root) {
            return {1, 0};
        }

        // Get information from left and right subtrees
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        // Current subtree is balanced if:
        // 1. Both subtrees are balanced
        // 2. Their heights differ by at most 1
        bool balanced =
            (left[0] == 1 && right[0] == 1) &&
            (abs(left[1] - right[1]) <= 1);

        // Height of current subtree
        int height = 1 + max(left[1], right[1]);

        // Return: {isBalanced, height}
        return {balanced ? 1 : 0, height};
    }
};
