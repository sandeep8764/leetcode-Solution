
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, long long> mp;
        mp[0] = 1;

        long long prefix_sum = 0;
        long long count = 0;

        // Count all subarrays whose sum is divisible by k
        for (int x : nums) {
            prefix_sum = (prefix_sum + x) % k;

            count += mp[prefix_sum];
            mp[prefix_sum]++;
        }

        // Remove duplicate subarrays consisting of equal values
        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && nums[j] == nums[i]) {
                j++;
            }

            int len = j - i;

            for (int h = 1; h <= len; h++) {
                if (1LL * nums[i] * h % k == 0) {
                    count -= (len - h);
                }
            }

            i = j;
        }

        return count;
    }
};
