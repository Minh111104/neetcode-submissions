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
    // Points to the next root value in preorder
    int preorderIdx = 0;
    // Stores: node value -> index in inorder
    unordered_map<int,int> inorderIdx;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build a lookup table for inorder positions
        for (int i = 0; i < inorder.size(); i++) {
            inorderIdx[inorder[i]] = i;
        }
        // Build the tree using the full inorder range
        return helper(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int start, int end) {
        // No values remain for this subtree
        if (start > end) {
            return nullptr;
        }

        // The next preorder value is the root
        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root's position in inorder
        int mid = inorderIdx[rootVal];

        // Values before mid form the left subtree
        root->left = helper(preorder, start, mid - 1);
        
        // Values after mid form the right subtree
        root->right = helper(preorder, mid + 1, end);

        return root;
    }
};
