
class Solution {
public:

    // Helper function: Check whether destination is reachable
    bool dfs(unordered_map<int, vector<int>>& adj,
             vector<bool>& visited, int u, int v) {

        // Destination reached
        if (u == v)
            return true;

        visited[u] = true;

        for (int neighbor : adj[u]) {

            if (!visited[neighbor]) {

                if (dfs(adj, visited, neighbor, v))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // Number of edges
        int n = edges.size();

        // Create adjacency list
        unordered_map<int, vector<int>> adj;

        // Process edges one by one
        for (int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            // Visited array
            vector<bool> visited(n + 1, false);

            // Check whether a path already exists
            if (dfs(adj, visited, u, v)) {
                return {u, v};
            }

            // Add the edge to the undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
