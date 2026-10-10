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
    vector<int> rightSideView(TreeNode* root) {
        // Right side view of the Binary tree 
        // to store the values 
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root==nullptr) return ans;
        while(!q.empty())
        {
            int size=q.size();
            
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* rt=q.front();
                q.pop();
                level.push_back(rt->val);
                if(rt->left)
                {
                    q.push(rt->left);
                }
                if(rt->right)
                {
                    q.push(rt->right);
                }

            }
            int n=level.size();
            ans.push_back(level[n-1]);
            
        }
        return ans;
        
    }
};