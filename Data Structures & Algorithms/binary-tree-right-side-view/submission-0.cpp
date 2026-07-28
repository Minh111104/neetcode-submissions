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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        if (!root) { // Empty tree has no right-side view
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);

        // Process the tree level by level
        while (!q.empty()) {
            int levelSize = q.size(); // since the queue size changes as nodes are removed/added
            int rightMostValue = 0;

            for (int i = 0; i < levelSize; i++) { // Traverse all nodes in the current level
                TreeNode* node = q.front();
                q.pop();

                // Keep updating; after the loop, this will be the last (rightmost) node
                rightMostValue = node->val;

                // Add children for the next level
                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(rightMostValue); // Store the rightmost node of this level
        }
        return res;
    }
};