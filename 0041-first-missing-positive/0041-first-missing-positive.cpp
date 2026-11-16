class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // in this we have ti use o(n) ant space o(1)
        // so i canmodify in the original arrays
        int n=nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > n + 1) {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                int idx = val - 1;
                if (nums[idx] > 0) {
                    nums[idx] = -nums[idx];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};