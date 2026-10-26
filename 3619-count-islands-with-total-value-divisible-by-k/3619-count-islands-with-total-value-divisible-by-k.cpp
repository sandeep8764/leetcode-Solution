class Solution {
public:
    int r, c;
    long long   dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0)
            return 0;

        int val = grid[i][j];
        grid[i][j] = 0;
        long long  sum = val;
        sum += dfs(grid, i - 1, j);
        sum += dfs(grid, i + 1, j);
        sum += dfs(grid, i, j - 1);
        sum += dfs(grid, i, j + 1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        r = grid.size();
        c = grid[0].size();
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] != 0) {

                  long long   sum = dfs(grid, i, j);
                    if (sum % k == 0)
                        count++;
                }
            }
        }
        return count;

    }
    
};
