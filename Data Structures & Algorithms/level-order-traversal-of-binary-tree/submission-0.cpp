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
    vector<vector<int>> res; // res[depth] stores all node values at that depth

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0); // The root begins at depth 0

        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) { // Stop when we reach an empty child
            return;
        }

        // If this is the first node encountered at this depth, create a new vector for this level
        if (res.size() == depth) {
            res.push_back(vector<int>());
        }

        // Add the current node to its corresponding level
        res[depth].push_back(node->val);

        // Children are one level deeper
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};