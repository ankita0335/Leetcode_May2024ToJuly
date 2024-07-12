class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void add(TreeNode* root) {
        if(!root)
            return;
        if(root->left)
            parent[root->left] = root;
        add(root->left);
        if(root->right)
            parent[root->right] = root;
        add(root->right);
    }
    void solve(TreeNode* target, int k, vector<int>&result) 
    {
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        while(!q.empty()) 
        {
            int n=q.size();
            if(k==0)
                break;
            while(n--) 
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited.count(curr->left->val)) 
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)) 
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if(parent.count(curr) && !visited.count(parent[curr]->val)) 
                {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while(!q.empty()) {
            TreeNode* tmp=q.front();
            q.pop();
            result.push_back(tmp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
        add(root);
        solve(target,k,result);
        return result;
    }
};
