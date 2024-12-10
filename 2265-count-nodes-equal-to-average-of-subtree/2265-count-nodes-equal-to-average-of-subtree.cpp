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
    int res = 0;
    pair<int,int>solve(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
       auto p1 = solve(root->left);
       auto p2 = solve(root->right);
        
        int totalSum = p1.first+p2.first+root->val;
        int totalCnt = p1.second+p2.second+1;
        
        int avg = totalSum/totalCnt;
        
        if(avg==root->val)
        {
            res+=1;
        }
        return {totalSum,totalCnt};
    }
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        solve(root);
        return res;
    }
};