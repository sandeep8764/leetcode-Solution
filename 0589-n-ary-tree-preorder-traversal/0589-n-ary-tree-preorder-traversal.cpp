/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
// Helper function for the reccursive calll 
void solve(Node* root, vector <int> & ans)
{
    // base Case Condition
    if(root==nullptr)
    {
        return ;
    } 
    // to store the root value
    ans.push_back(root->val);
    
    // so for the n ary Binary tree we use loop here 
    for(Node* child:root->children)
    {
        solve(child,ans);

    }
   
}
    vector<int> preorder(Node* root) {
        // Preorder traversal (root -> left -> right )
        // To store the Answer need vector arrays 
        // here n ary Binary tree is given 
        vector<int> ans;
        solve(root, ans);
        return ans;
        
    }
};