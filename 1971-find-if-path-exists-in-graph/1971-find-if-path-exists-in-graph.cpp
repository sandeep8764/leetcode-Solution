class Solution {
public:
    //  Helper function for this
    bool dfs(int node, int destination, vector<vector<int>>& adj,
             vector<bool> &visited) {
        //  Base case condition
        if (node == destination)
            return true;
        // track of the visited nodes
        visited[node]=true;
        // visist the neighbours 
        for(int neighbour:adj[node])
        {
            if(!visited[neighbour])
            {
                if(dfs(neighbour,destination,adj,visited)) return true;

            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        // Bidirectional grapgh is given
        //  n vertices, edges, source , destination is given  Directed grpah is
        //  given find path for the Source to destination Grapgh +DFS/BFS usesd
        //  here

        vector<vector<int>> adj(n); // create the adjecency list 
        vector<bool> visited(n, false); // track for  the visiting the nodes

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       return  dfs(source,destination,adj,visited);
        
    }
};