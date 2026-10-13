class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); // number of rows 
        int m=grid[0].size(); // number of colimns 
        queue<pair<int,int> >q;
        int fresh=0;
        // Step A: Traverse the grid.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        // step02 if no fresh ornages are left   
        if(fresh==0) return 0;
        // step03 set the four deirection for the movements  
        // Up Down , left , right
        // int dr[4]={-1,0,+1,0};
        // int dc[4]={0,+1,0,-1};   
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int minutes=0;

        // Now Use of BFS 
        while(!q.empty())
        {
            int size=q.size();
            bool rotted=false;
            for(int i=0;i<size;i++)
            {
                auto[r,c]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int nr=r+dr[d];
                    int nc=c+dc[d];
                    // check the Boundaries 
                    if(nr>=0  && nr<n && 
                        nc>=0 && nc<m &&
                        grid[nr][nc]==1 )
                        {
                            grid[nr][nc]=2;
                            fresh--;
                            q.push({nr,nc});
                            rotted=true;

                        }

                }
            }
            if(rotted==true)
            {
                minutes++;
            }

        }
return fresh==0 ?minutes:-1;
        
    }
};