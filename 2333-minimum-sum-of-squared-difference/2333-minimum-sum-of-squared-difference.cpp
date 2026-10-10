class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        
        long long total = 0;
        for (int d : diff) {
            total += d;
        }

        if (k >= total) return 0;

        int low = 0, high = maxi;

        
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int limit = low;
        long long ans = 0;
        long long remaining = k;

        // Reduce every difference above the limit
        for (int d : diff) {
            if (d > limit) {
                remaining -= d - limit;
                d = limit;
            }
            ans += 1LL * d * d;
        }

        
        if (limit > 0 && remaining > 0) {
            ans -= remaining * (2LL * limit - 1);
        }

        return ans;
    }
};