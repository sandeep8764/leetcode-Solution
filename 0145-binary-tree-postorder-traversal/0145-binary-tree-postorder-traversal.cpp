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
// Helper function for the postorder 
void solve(TreeNode* root,vector<int> &ans)
{
    if(root==nullptr)
    {
        return ;
    }
    solve(root->left,ans);
    solve(root->right,ans);
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        // Post order traversal (left,right, root)
        // Binary tree measn 2 solve or reccursive function are used 
        vector<int> ans;
        solve(root,ans);
        return ans;
        
    }
};