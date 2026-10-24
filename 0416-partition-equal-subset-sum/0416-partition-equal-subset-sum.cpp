class Solution {
public:
    // Helper function
    bool solve(vector<int>& nums, int n, int i, int target,vector<vector<int>> &dp) {
        if (i == n) {
            if (target == 0) {
                return true;
            }
            return false;
        }
        if(dp[i][target]!=-1) return dp[i][target] ;

        if (nums[i] > target) {
            return dp[i][target]=solve(nums, n, i + 1, target,dp);
        }
        bool take = solve(nums, n, i + 1, target - nums[i],dp);
        bool skip = solve(nums, n, i + 1, target,dp);
        return dp[i][target]= take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        
        for (int x : nums) {
            total += x;
        }
        // now we have to divide it into 2 arrays total/2;
        // first check can be possible or not
        if (total % 2 != 0)
            return false;
        int target = total / 2; // divide it into equal part sum
        // Here i can target is variable (so create 2D DP for this )
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(nums, n, 0, target,dp);
    }
};