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
//  helper function to Reccursive calling 
    void solve(Node * root, vector<int> &ans)
    {
        // Base case Condition 
        if(root==nullptr)
        {
            return ;
        }
        // left traversal
        for(Node *child:root->children)
        {
            solve(child,ans);
        }
        ans.push_back(root->val);
    }



    vector<int> postorder(Node* root) {
        // post-order traversal (left, right, root)
        // Need 2 d Vector to store the answer 
        vector<int> ans;
        
        solve(root, ans);
        return ans;
    }
};