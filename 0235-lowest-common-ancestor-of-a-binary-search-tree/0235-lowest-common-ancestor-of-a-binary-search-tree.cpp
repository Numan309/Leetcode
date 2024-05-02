/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        // If both values are less than the current root, search in the left subtree
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // If both values are greater than the current root, search in the right subtree
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        // If one value is greater and one value is less than the current root,
        // or one value matches the root value, then this is the LCA
        else
            return root;
    }
};
