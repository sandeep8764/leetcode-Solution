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
            int u=time[0];
            int v=time[1];
            int wt=time[2];
            adj[u].push_back({v,wt});
        }

        // craete the min_heap(distnace , nodes )
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>> 
            >pq;
            // push the source nodes 
            pq.push({0,k});


            //  now use dijskrta Algorithm 
            while(!pq.empty())
            {
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                if(d>dist[node]) continue;
                for(auto & it:adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    
                    if(d+wt<dist[v])
                    {
                        dist[v]=d+wt;
                        pq.push({dist[v],v});
                    }
                }
            }
            // find the maximum distanec 
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(dist[i]==1e9) return -1;
                ans=max(ans,dist[i]);

            }
            return ans;


    }
};