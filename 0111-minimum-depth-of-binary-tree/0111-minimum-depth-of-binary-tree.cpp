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
        int ans=0;
        if(root==nullptr) return 0;
        
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(left==0 || right==0) 
        {
            ans=max(left,right);
            return 1+ans;
        }
        ans=min(left,right);
        return 1+ans;
        
    }
};