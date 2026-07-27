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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // An empty tree is a subtree of any tree
        if (!subRoot) {
            return true;
        }

        // A non-empty subRoot cannot be found in an empty root
        if (!root) {
            return false;
        }

        // Check whether the trees are identical starting at this node
        if (sameTree(root, subRoot)) {
            return true;
        }

        // Otherwise, search in the left and right subtrees
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

private:
    bool sameTree(TreeNode* root1, TreeNode* root2) {
        // Both trees ended at the same time
        if (!root1 && !root2) {
            return true;
        }

        // One tree ended before the other
        if (!root1 || !root2) {
            return false;
        }

        // Current values must match, and both subtrees must match
        return root1->val == root2->val &&
               sameTree(root1->left, root2->left) &&
               sameTree(root1->right, root2->right);
    }
};