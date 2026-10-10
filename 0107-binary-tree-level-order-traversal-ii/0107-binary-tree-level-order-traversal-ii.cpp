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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // Level Order traversal here Then BFS+Reverse The Result 

        // Step01 2D Vector to store the result 
        vector<vector<int>> ans;
        
        if(root==nullptr) return ans ;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            vector<int>level;
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
            ans.push_back(level);

        }
         reverse(ans.begin(),ans.end());
         return ans;
        
    }
};