class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Here WE can obserev that Weight edges are Posistive then think about the Dijkstra Algorithm 
        // n nodes are Given and Directed grapgh is given (src, des, wt)
        vector<int> dist(n+1,1e9);
        dist[k]=0; // source nodes filled with 0 time delasy 

        // craete the adjacency list 
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &time:times)
        {
            int u=time[0]; // source 
            int v=time[1]; // distination
            int wt=time[2]; // distance 
            adj[u].push_back({v,wt}); // now create the adjacency list 
        }

        // craete the min_heap(distnace , nodes )
        // Even How to Define the minheap (type , continer , condition )
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>> 
            >pq;
            // push the source nodes 
            pq.push({0,k}); // ({distance, node })


            //  now use dijskrta Algorithm 
            // now use Dijkstra Algorithm 
            while(!pq.empty())
            {
                int d=pq.top().first; // distance 
                int node=pq.top().second; // node 
                pq.pop(); // pop it from Queue 
                if(d>dist[node]) continue; // now comapare it from the Distnave Arrays 
                for(auto & it:adj[node]){
                    // now go to adjacnecy lis and check for the other nodes 
                    int v = it.first; // distination 
                    int wt = it.second; // distance 
                    
                    if(d+wt<dist[v])
                    {
                        dist[v]=d+wt;
                        pq.push({dist[v],v});
                    }
                }
            }
            // find the maximum distanec (beacus ein min time signals approach to all signasl )
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(dist[i]==1e9) return -1;
                ans=max(ans,dist[i]);

            }
            return ans;


    }
};