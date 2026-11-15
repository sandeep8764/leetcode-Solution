class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        sort(nums.begin(),nums.end());
        int max_sum = 0;
        while (i < j) {
            int sum = nums[i] + nums[j];
            max_sum = max(max_sum, sum);
            i++;
            j--;
        }
        return max_sum;
    }
};