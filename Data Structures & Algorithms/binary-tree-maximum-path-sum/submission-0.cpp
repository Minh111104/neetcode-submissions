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
    int maxPathSum(TreeNode* root) {
        // Initialize with root value because all values may be negative
        int res = root->val;

        dfs(root, res);

        return res;
    }
private:
    // Returns the maximum downward path sum starting at this node.
    // The returned path can use at most one child.
    int dfs(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }

        // Ignore negative subtree contributions
        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);

        // Best complete path passing through this node
        res = max(res, root->val + leftMax + rightMax);

        // Return an extendable path to the parent:
        // current node plus the better child branch
        return root->val + max(leftMax, rightMax);
    }
};