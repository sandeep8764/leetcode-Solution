// class Solution {
// public:
//     // helper function try to solve using Reccursion 
//     int memo[105][105][205];
//     bool solve(int i,int j,int count, vector<vector<char>> &grid)
//     {
//         int m=grid.size();
//         int n=grid[0].size();
//         // out of bounds check 
//         if(i>m-1 || j>n-1) 
//         {
//             return count==0;
//         }
        
        
//        if(grid[i][j]=='(')
//        {
//         count++;
//        }
//       else 
//       {
//         count--;
//       }
//       if(count<0)
//       {
//         return false;
//       }
//       // retunr memoized values that are already calculated 
//       if(memo[i][j][count]!=-1)
//       {
//         return memo[i][j][count];
//       }
//        // Down Movement (i+1)
//        if(solve(i+1,j,count,grid)==true)
//        {
//         return true;
//        }
//        // Right Movement j+1
//        else if(solve(i,j+1,count,grid)==true)
//        {
//         return true;
//        }
//        else 
//        {
//         return false;
//        }

//     }
//     bool hasValidPath(vector<vector<char>>& grid) {
//         // Return true if valid pah is exist so we have to find the valid path 
//         // start from (0,0) to end at (m-1,n-1)
//         // Number of rows==m
//         // number of columns==n

//         int m=grid.size(); // Rows 
//         int n=grid[0].size(); // Columns 
//         // path length is always even 
//         if((m+n-1)%2!=0) return false;
//         if(grid[0][0]==')' || grid[m-1][n-1]=='(') return false;
//         // reset memo table for the every case
//         memset(memo,-1,sizeof(memo));
        
//         return solve(0,0,0,grid);
       

        
//     }
// };
class Solution {
public:
    int memo[105][105][205];

    bool solve(int i, int j, int count, vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Out of bounds check MUST return false
        if (i >= m || j >= n) {
            return false;
        }

        // 2. Process current cell
        if (grid[i][j] == '(') {
            count++;
        } else {
            count--;
        }

        // 3. Early pruning (more closing brackets than open ones)
        if (count < 0) {
            return false;
        }

        // 4. Base case: Reached bottom-right target cell
        if (i == m - 1 && j == n - 1) {
            return count == 0;
        }

        // 5. Check cache / memoized state
        if (memo[i][j][count] != -1) {
            return memo[i][j][count];
        }

        // 6. Recurse Down and Right
        bool down = solve(i + 1, j, count, grid);
        bool right = solve(i, j + 1, count, grid);

        return memo[i][j][count] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length parity check
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // Reset memo table before starting
        memset(memo, -1, sizeof(memo));

        return solve(0, 0, 0, grid);
    }
};