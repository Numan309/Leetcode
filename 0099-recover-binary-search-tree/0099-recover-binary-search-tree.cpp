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
    vector<int> ans;
    int i=0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    void check(TreeNode* root){
        if(!root) return;
        check(root->left);
        if(ans[i]!=root->val) swap(ans[i],root->val);
        i++;
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(ans.begin(),ans.end());
        check(root);
    }
};