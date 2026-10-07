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
// Helper function for the reccirsion calling 
    void solve(TreeNode* root,vector<int> &ans)
    {
        // base Case Condiotin (tpo Break the Condition 
        
        if(root==nullptr)
        {
            return ;
        }
        ans.push_back(root->val);
         solve(root->left,ans);
         solve(root->right,ans);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        // Here we have to traverse the Preorder traversal 
        // root -> left -> right
        vector<int> ans;
        solve(root,ans);
        return ans;


    }
};