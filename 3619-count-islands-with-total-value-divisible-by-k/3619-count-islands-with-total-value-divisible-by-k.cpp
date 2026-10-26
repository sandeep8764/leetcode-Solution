class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        if (r == 0) return 0;

        int c = grid[0].size();
        if (c == 0) return 0;

        int count = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] != 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    long long sum = grid[i][j];
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx >= 0 && ny >= 0 &&
                                nx < r && ny < c &&
                                grid[nx][ny] != 0) {

                                sum += grid[nx][ny];
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }

                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};