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
     int count=0;
     // helper Function 
     pair<int,int> dfs(TreeNode* node)
     {
        if(!node) return {0,0};
        auto left=dfs(node->left);
        auto right=dfs(node->right);

        int current_sum=node->val+left.first+right.first;
        int current_count=1+left.second+right.second;
        if(current_sum/current_count==node->val)
        {
            count++;
        }
        return {current_sum,current_count};
     }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
        
        
    }
};