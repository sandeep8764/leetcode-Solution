class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Simply can be calculate dby Running Sum or Prefix_sum 
        int n=nums.size();

        vector<int> prefix_sum(n); // vector with size n with all value is zero 
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
            // at index i =previous one + current element 

        }
        return prefix_sum;

        
    }
};