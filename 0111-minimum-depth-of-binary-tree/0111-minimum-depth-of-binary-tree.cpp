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
    int minDepth(TreeNode* root) {
        // Create a Queue 
        if(root==nullptr) return 0;
        queue<TreeNode*>q;
        q.push(root);
        
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* rt=q.front();
                q.pop();
                if(rt->left==nullptr && rt->right==nullptr)
                {
                    return level;
                }
                if(rt->left!=nullptr)
                {
                    q.push(rt->left);

                }
                if(rt->right!=nullptr)
                {
                    q.push(rt->right);

                }
                
                
            }
            level++;


        }
        return level;
    }
};