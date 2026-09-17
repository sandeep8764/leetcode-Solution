class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> min_len(n, INT_MAX);
        int ans = INT_MAX;
        int window_sum = 0;
        int i = 0;
        
        for (int j = 0; j < n; j++) {
            window_sum += arr[j];
            
            while (window_sum > target && i <= j) {
                window_sum -= arr[i];
                i++;
            }
            
            // 1. Carry forward the minimum length seen prior to index j
            if (j > 0) {
                min_len[j] = min_len[j - 1];
            }
            
            // 2. Process when a valid subarray sum is found
            if (window_sum == target) {
                int curr_len = j - i + 1;
                
                // Check if a non-overlapping valid subarray exists before index i
                if (i > 0 && min_len[i - 1] != INT_MAX) {
                    ans = min(ans, curr_len + min_len[i - 1]);
                }
                
                // Update min_len[j] (handles both j = 0 and j > 0)
                min_len[j] = min(min_len[j], curr_len);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};