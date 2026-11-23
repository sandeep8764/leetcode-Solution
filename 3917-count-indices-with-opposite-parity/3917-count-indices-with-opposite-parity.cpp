class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // now us ethe 2 loops
        for (int i = 0; i < n; i++) {
             int count = 0;
             
            for (int j = i; j < n; j++) {
                if(nums[i]%2!=nums[j]%2)
                {
                    count++;
                }
                ans[i]=count;
              
            }
        }
        return ans;
    }
};