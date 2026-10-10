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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // tree IS Given Binary tree 
        // Most Updated code may be DFS 
        if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr)
        {
            return root->val==targetSum;
        }
       int remin=targetSum-root->val;
       return hasPathSum(root->left, remin) ||hasPathSum(root->right, remin);
        
        


        
    }
};