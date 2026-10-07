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
        // helper Function to traverse Each level 
        void solve(Node* root,vector<vector<int>> &ans,int level)
        {
            // Base Case Condition
            if(root==nullptr)
            {
                return ;
            }
            if(ans.size()==level)
            {
                ans.push_back({});

            }
            ans[level].push_back(root->val);
            for(Node * child:root-> children)
            {
                solve(child,ans,level+1);
            }

        }
    vector<vector<int>> levelOrder(Node* root) {
        // Here Level order traversal is Given 
        // level By level values is Stored 
        // so we Need 2 d vector to store the values 

        vector<vector<int>> ans;
        vector<int> current;
        solve(root, ans, 0);
        return ans;
    }
};