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
    string convert(vector<int>&temp)
    {
        string ans = "";
        int n = temp.size();
        for(int i=0;i<n-1;i++)
        {
            ans+=to_string(temp[i]);
            ans.push_back('-');
            ans.push_back('>');
        }
        ans+=to_string(temp[n-1]);
        return ans;
    }
    void solve(TreeNode* root,vector<int>&temp,vector<string>&ans)
    {
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL)
        {
            temp.push_back(root->val); 
            ans.push_back(convert(temp));
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        solve(root->left,temp,ans);
        solve(root->right,temp,ans);
        temp.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>temp;
        vector<string>ans;
        solve(root,temp,ans);
        return ans;
    }
};