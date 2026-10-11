/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //  Helper function for the traversal in Tree
    void solve(Node* root) {
        if (root == nullptr)
            return;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* rt = q.front();
                q.pop();
// 
                if (i == size - 1) {
                    rt->next == nullptr;
                } else {
                    Node* rt1 = q.front();
                    rt->next = rt1;
                }
                if (rt->left) {
                    q.push(rt->left);
                }
                if (rt->right) {
                    q.push(rt->right);
                }
            }
            // ans.push_back(level);
            // ans.push_back(nullptr);
        }
    }
    Node* connect(Node* root) {

        // level by level order traversal and separated by #
        //  BFS Solution

        solve(root);
        return root;
    }
};