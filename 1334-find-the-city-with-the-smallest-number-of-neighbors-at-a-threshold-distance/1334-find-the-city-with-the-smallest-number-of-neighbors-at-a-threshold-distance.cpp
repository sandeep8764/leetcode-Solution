class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Tere are n cities ( 1 to n-1)
        // arrays of edges are given ( source, detination, weight)
        // grapgh is bi directional ( both Ways flows )
         const int INF=1e8;

        // step 01 create the adajacency  matrix of each city track 
        vector <vector<int>> dist(n,vector<int>(n, INF)); // 2D matrix 

        // distance from itself is zero 
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            dist[u][v]=wt;
            dist[v][u]=wt;

        }
        // stepo 02 upadte the matrix from eacjh city anfd reaxlation each terma 
        // step o03 now floyd warshal algorithm 
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]!=INF &&dist[k][j]!=INF)
                    {
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
       // now create the priority Queue for the max elements 
    //    priority_queue<pair<int, int>> max-heap;
int ans=-1;
int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)
                {
                    count++;
                   
                }
            }
            if(count<=min)
            {
                min=count;
                ans=i;
            }
        }
        return ans;


    }
};