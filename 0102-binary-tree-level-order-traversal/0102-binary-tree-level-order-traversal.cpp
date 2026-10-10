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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
    // Level By Level Order Traveral 
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            TreeNode* rt=q.front();
            q.pop();
            level.push_back(rt->val);
            if(rt->left!=nullptr)
            {
                q.push(rt->left);
            }
            if(rt->right!=nullptr)
            {
                q.push(rt->right);
            }

        }
        ans.push_back(level);
    }
    return ans;

        
    }
};