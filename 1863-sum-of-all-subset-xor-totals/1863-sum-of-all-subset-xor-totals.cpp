class Solution {
public:
    // using the recursion we can easily solve this

    void solve(vector<int>& nums, int i, int xor_value, int& sum) {
        if (i == nums.size()) {
            sum += xor_value;
            return;
        }
        // include the current element
        solve(nums, i + 1, xor_value ^ nums[i], sum);

        // exclude the current element

        solve(nums, i+1, xor_value, sum);
    }
    int subsetXORSum(vector<int>& nums) {

        int sum = 0;
        solve(nums, 0, 0, sum);
        return sum;
    }
};