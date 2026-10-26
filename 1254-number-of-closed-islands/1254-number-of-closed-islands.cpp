class Solution {
public:
    int r, c;
    // bool dfs(vector<vector<int>>& grid, int i, int j)
    // {
    //     if(i<0 ||j<0||i>=r || j>=c)
    //     {
    //         return false;
    //     }
    //     if(grid[i][j]==1) return true;
    //      grid[i][j] = 1;
    //      bool up=dfs(grid,i-1,j);
    //      bool bottom=dfs(grid,i+1,j);
    //      bool left=dfs(grid,i,j-1);
    //      bool right=dfs(grid,i,j+1);
    //      return up && bottom && left && right;
    // }
    bool bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 1;
        bool closed = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // If land touches the boundary, it is not closed
            if (x == 0 || y == 0 || x == r - 1 || y == c - 1) {
                closed = false;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 &&
                    nx < r && ny < c &&
                    grid[nx][ny] == 0) {

                    grid[nx][ny] = 1;  // Mark visited
                    q.push({nx, ny});
                }
            }
        }
        return closed;

    }
    int closedIsland(vector<vector<int>>& grid) {
        // Given 2D arrays consist of the 0 (land) and 1 (water )
        // Movement onluy in 4 direction
        // We have to use reccursicva calling and the
        // we have to also track of the visisted cell
        r = grid.size();    // Number of the Rows
        c = grid[0].size(); // number of the  Columns
        int count = 0;
        for (int i = 0; i < r; i++) {
            {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == 0) {
                        if (bfs(grid, i, j)) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};