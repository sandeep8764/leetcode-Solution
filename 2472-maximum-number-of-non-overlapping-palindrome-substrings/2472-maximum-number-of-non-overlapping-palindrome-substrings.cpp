class Solution {
public:
    bool ispalindrome(string &s, int i, int j,
                 vector<vector<int>> &pal)
{
    if(i >= j)
        return true;

    if(pal[i][j] != -1)
        return pal[i][j];

    if(s[i] != s[j])
        return pal[i][j] = false;

    return pal[i][j] = ispalindrome(s, i + 1, j - 1, pal);
}

int solve(string &s, int k, int i, int j,
          vector<vector<int>> &dp,
          vector<vector<int>> &pal)
{
    int n = s.length();

    if(i >= n || j >= n)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(ispalindrome(s, i, j, pal))
    {
        int take = 1 + solve(s, k, j + 1, j + k, dp, pal);

        int grow = solve(s, k, i, j + 1, dp, pal);

        int slide = solve(s, k, i + 1, j + 1, dp, pal);

        return dp[i][j] = max({take, grow, slide});
    }
    else
    {
        int grow = solve(s, k, i, j + 1, dp, pal);

        int slide = solve(s, k, i + 1, j + 1, dp, pal);

        return dp[i][j] = max(grow, slide);
    }
}
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        vector<vector<int>> pal(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, dp, pal);
            
    }
};