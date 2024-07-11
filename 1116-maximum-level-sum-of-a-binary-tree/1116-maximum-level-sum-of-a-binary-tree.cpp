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
    int maxLevelSum(TreeNode* root) 
    {
        if (!root) 
            return 0;
        int maxi=INT_MIN;
        int level=0;
        int curr=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left!=nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);
            }
            if(sum>maxi)
            {
                maxi=sum;
                level=curr;
            }
            curr++;
        }
        return level;
    }
};