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
    bool isValidBST(TreeNode* root) {
        // The root can initially be any valid int value.
        return valid(root, LONG_MIN, LONG_MAX);
    }

private:
    // Checks whether every node in this subtree lies strictly between minimum and maximum
    bool valid(TreeNode* node, long minimum, long maximum) {
        if (!node) { // An empty subtree is valid
            return true;
        }

        // The current value must stay inside its allowed range
        if (node->val <= minimum || node->val >= maximum) {
            return false;
        }

        // Left subtree values must be less than node->val
        // Right subtree values must be greater than node->val
        return valid(node->left, minimum, node->val) &&
               valid(node->right, node->val, maximum);
    }
};
