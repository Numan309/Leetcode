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
    int ans = 0;

    void solve(TreeNode* root, long long targetSum) { // Use long long to prevent overflow
        if (root == NULL) return;

        // Check if the current node is part of a valid path
        if (targetSum == root->val) ans++;

        // Continue the path sum search in left and right children
        solve(root->left, targetSum - root->val);
        solve(root->right, targetSum - root->val);
    }

    void findPaths(TreeNode* root, long long targetSum) { // Use long long here too
        if (root == NULL) return;

        // Start a new path from the current node
        solve(root, targetSum);

        // Recur for left and right subtrees
        findPaths(root->left, targetSum);
        findPaths(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        ans = 0; // Reset the answer
        findPaths(root, static_cast<long long>(targetSum)); // Cast to long long
        return ans;
    }
};
