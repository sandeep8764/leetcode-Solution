class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Here we have Given values of number of rows and columns
        if (m == 0 || n == 0)
            return {};

        vector<string> grid(m, string(n, '#'));
        // multiple path can be possible so we have to create obstacle in this
        for(int i=0;i<n;i++)
        {
            grid[0][i]='.'; // make the first rows free

        }
        // now make the last columns free
        for(int j=0;j<m;j++){
            grid[j][n-1]='.';
        }
        return grid;
    }
};