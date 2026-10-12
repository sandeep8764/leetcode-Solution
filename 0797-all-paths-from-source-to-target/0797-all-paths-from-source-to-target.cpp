class Solution {
public:
    //  helper function for this
    void solve(int start, int destination, vector<vector<int>>& graph,
                vector<vector<int>>& ans,
               vector<int>& one_path) {
                // base case condition
                if(start==destination)
                {
                    ans.push_back(one_path);
                    return ;

                }
                // Explore the All the neighbour 
                for(int neighbour:graph[start])
                {
                    one_path.push_back(neighbour);
                    solve(neighbour,destination,graph,ans,one_path);
                    // backtrack
                    one_path.pop_back();
                }

               }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // DAG is given
        // nodes is given (o , to n-1)
        // grapgh is Directed
        //  final output is Vector of 2D
        vector<vector<int>> ans;
        vector<int> one_path;

        // create the adjajency list for this
        // vector<vector<int>> adj(n);
        int destination=graph.size()-1;
        one_path.push_back(0);

        // From Graph We create the adj
        // for (auto& edge : graph) {
        //     int u = edge[0];
        //     int v = edge[1];

        //     adj(u).push_back(v);
        //     adj(v).push_back(u);
        // }
        solve(0, destination, graph, ans, one_path);
        return ans;
    }
};