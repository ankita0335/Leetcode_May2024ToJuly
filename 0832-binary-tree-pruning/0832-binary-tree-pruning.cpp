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
    TreeNode* deletee(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        root->left=deletee(root->left);
        root->right=deletee(root->right);
        if (root->val == 0 && root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return deletee(root);
    }
};