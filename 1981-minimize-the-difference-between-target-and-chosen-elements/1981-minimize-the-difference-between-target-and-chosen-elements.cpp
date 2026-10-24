
class Solution {
public:
    vector<int> suffixMin, suffixMax;
    vector<unordered_map<int, int>> dp;

    int solve(vector<vector<int>>& mat, int m, int i,
              int target, int sum) {

        // All rows have been processed
        if (i == m) {
            return abs(sum - target);
        }

        // Minimum possible final sum is already >= target
        if (sum + suffixMin[i] >= target) {
            return sum + suffixMin[i] - target;
        }

        // Maximum possible final sum is still <= target
        if (sum + suffixMax[i] <= target) {
            return target - sum - suffixMax[i];
        }

        // Check memoization
        if (dp[i].count(sum)) {
            return dp[i][sum];
        }

        int ans = INT_MAX;

        // Choose exactly one element from the current row
        for (int x : mat[i]) {
            ans = min(ans, solve(mat, m, i + 1,
                                 target, sum + x));

            if (ans == 0) {
                break;
            }
        }

        return dp[i][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();

        suffixMin.assign(m + 1, 0);
        suffixMax.assign(m + 1, 0);

        // Calculate minimum and maximum possible sums
        // from each remaining suffix of rows
        for (int i = m - 1; i >= 0; i--) {
            suffixMin[i] = suffixMin[i + 1]
                         + *min_element(mat[i].begin(), mat[i].end());

            suffixMax[i] = suffixMax[i + 1]
                         + *max_element(mat[i].begin(), mat[i].end());
        }

        dp.assign(m, unordered_map<int, int>());

        return solve(mat, m, 0, target, 0);
    }
};
