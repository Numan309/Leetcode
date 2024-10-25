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
    const int N = 1e9+7;
    long totalSumOfTree = 0;
    long maxP = 0;
    int TotalSum(TreeNode* root)
    {
        if(root==NULL) return 0;
        int left = TotalSum(root->left);
        int right = TotalSum(root->right);
        int sum = root->val+left+right;
        return sum;
    }
    int solve(TreeNode* root)
    {
        if(root==NULL) return 0;
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        long subTreeSum = root->val+leftSum+rightSum;//s1
        long s2 = totalSumOfTree-subTreeSum;
        maxP = max(maxP,subTreeSum*s2);
        
        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;
         maxP = 0;
        totalSumOfTree = TotalSum(root);
        solve(root);
        return (maxP)%N;
    }
};