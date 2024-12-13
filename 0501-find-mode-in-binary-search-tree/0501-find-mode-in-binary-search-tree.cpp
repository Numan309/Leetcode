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
    unordered_map<int,int>m;
    
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        solve(root->left);
        m[root->val]++;
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        
        vector<int>res;
        
        int maxFreq = 0;
        
        for(auto &it:m)
        {
          if(it.second>maxFreq)
          {
              maxFreq = it.second;
              res = {};
              res.push_back(it.first);
          }else if(it.second==maxFreq){
              res.push_back(it.first);
          }
        }
        return res;
    }
};