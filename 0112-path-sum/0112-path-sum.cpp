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
    void solve(TreeNode* &root,int targetSum, vector<vector<int>>&res,vector<int>tmp,int sum)
    {
        if(!root)   return ;
        sum+=root->val;
        tmp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
                res.push_back(tmp);
            return;
        }
        solve(root->left,targetSum,res,tmp,sum);
        solve(root->right,targetSum,res,tmp,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int sum=0;
        vector<int>tmp;
        vector<vector<int>>res;
        solve(root,targetSum,res,tmp,sum);
        if(res.size()>0)
            return true;
        else
            return false;
    }
};