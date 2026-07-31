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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res; // Stores the inorder traversal (sorted order)

        dfs(root, res);

        // Vector uses 0-based indexing, so the kth smallest element is at index k-1.
        return res[k - 1];
    }

private:
    void dfs(TreeNode* node, vector<int>& res) {
        if (!node) { // Empty subtree
            return;
        }

        dfs(node->left, res); // Visit left subtree (smaller values)
        res.push_back(node->val); // Visit current node
        dfs(node->right, res); // Visit right subtree (larger values)
    }
};
