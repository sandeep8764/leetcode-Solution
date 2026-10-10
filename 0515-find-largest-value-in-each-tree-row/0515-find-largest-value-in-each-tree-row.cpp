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
    vector<int> largestValues(TreeNode* root) {
        //  largest values in Each level 
        vector<int> ans;
        queue<TreeNode*>q;
        if(root==nullptr)
        {
            return ans;
        }
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
            int max=INT_MIN;
            for(int x:level)
            {
                if(x>max)
                {
                    max=x;
                }
            }
            ans.push_back(max);
        }
        return ans;
        
    }
};